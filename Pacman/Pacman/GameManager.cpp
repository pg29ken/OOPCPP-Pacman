// Copyright @ Ken Arigo - VFS 2025-2026

#include "GameManager.hpp"
#include "TickManager.hpp"	
#include "InputManager.hpp"
#include "Board.hpp"
#include "Pacman.hpp"
#include "Ghost.hpp"
#include <cstdlib>
#include <windows.h>

GameManager* GameManager::_sInstance = nullptr;

void GameManager::PauseGame()
{
	InputManager inputManager;
	TickManager::GetInstance()->StopAutoTick();
	bool inMenu = true;
	int selectedOption = 0; // 0 = Continue, 1 = Restart, 2 = Exit
	bool keyWasPressed = false;

	std::system("cls");
	MenuGraphics::PauseContinue();

	while (inMenu)
	{
		inputManager.Update();
		const InputState& state = inputManager.GetState();

		if (state.IsEnter())
		{
			switch (selectedOption)
			{
			case 0:
				inMenu = false;
				TickManager::GetInstance()->StartAutoTick();
				std::system("cls");
				GetInstance()->_gameBoard->RenderBoard();
				break;
			case 1:
				StartGame();
				inMenu = false;
				break;
			case 2:
				std::exit(0);
				return;
			}
		}
		else if (state.IsUp() || state.IsDown())
		{
			if (!keyWasPressed)
			{
				std::system("cls");

				if (state.IsUp())
				{
					selectedOption--;
					if (selectedOption < 0) selectedOption = 2;
				}
				else if (state.IsDown())
				{
					selectedOption++;
					if (selectedOption > 2) selectedOption = 0;
				}

				switch (selectedOption)
				{
				case 0: MenuGraphics::PauseContinue(); break;
				case 1: MenuGraphics::PauseRestart(); break;
				case 2: MenuGraphics::PauseExit(); break;
				}

				keyWasPressed = true;
			}
		}
		else
		{
			keyWasPressed = false;
		}

		Sleep(50);
	}
}

void GameManager::StartMenu()
{
	InputManager inputManager;
	TickManager::GetInstance()->StopAutoTick();
	bool inMenu = true;
	int selectedOption = 0; // 0 = Start, 1 = Exit
	bool keyWasPressed = false; // Debounce flag

	std::system("cls");
	MenuGraphics::StartMenuStart();
	while (inMenu)
	{
		inputManager.Update();
		const InputState& state = inputManager.GetState();

		// Only process input when key is freshly pressed (not held)
		if (state.IsEnter())
		{
			switch (selectedOption)
			{
			case 0:
				inMenu = false;
				TickManager::GetInstance()->StartAutoTick();
				StartGame();
				break;
			case 1:
				inMenu = false;
				
				break;
			}
		}
		else if (state.IsUp() || state.IsDown())
		{
			if (!keyWasPressed)
			{
				std::system("cls");

				if (state.IsUp())
				{
					selectedOption--;
					if (selectedOption < 0) selectedOption = 1;
				}
				else if (state.IsDown())
				{
					selectedOption++;
					if (selectedOption > 1) selectedOption = 0;
				}

				switch (selectedOption)
				{
				case 0: MenuGraphics::StartMenuStart(); break;
				case 1: MenuGraphics::StartMenuExit(); break;
				}

				keyWasPressed = true;
			}
		}
		else
		{
			keyWasPressed = false;
		}

		

		Sleep(50);
	}
}
//void GameManager::EndScreen()
//{
//	TickManager::GetInstance()->StopAutoTick();
//	std::system("cls");
//}

void GameManager::StartGame()
{
	GetInstance()->_points = 0;
	std::system("cls");
	InputManager inputManager;
	const InputState& state = inputManager.GetState();
	GetInstance()->_gameBoard = new Board;
	Pacman pacman(GetInstance()->_pacmanStartPos);

	GetInstance()->_ghosts.clear(); // Clear any old ghosts
	GetInstance()->_ghosts.push_back(new Ghost("Blinky", GetInstance()->_ghostHome));
	GetInstance()->_ghosts.push_back(new Ghost("Pinky", GetInstance()->_ghostHome));


	GetInstance()->_gameBoard->RenderBoard();
	GetInstance()->_gameBoard->ChangeCell(pacman.GetPosition(), 'p');

	TickManager::GetInstance()->StartAutoTick(1000);
	GetInstance()->_isGameRunning = true;
	while (GetInstance()->_isGameRunning) {
			//Pacman Input
		inputManager.Update();
		MoveDirection previousDir = pacman.GetDirection();
		if (inputManager.IsButtonDown()) 
		{
			if (state.IsUp()) pacman.SetDirection(MoveDirection::UP);
			if (state.IsDown()) pacman.SetDirection(MoveDirection::DOWN);
			if (state.IsLeft()) pacman.SetDirection(MoveDirection::LEFT);
			if (state.IsRight()) pacman.SetDirection(MoveDirection::RIGHT);
			if (state.IsEscape()) PauseGame();
		}
		std::pair<int, int>  currentPos = pacman.GetPosition();
		std::pair<int, int> checkNewPos = pacman.TryGetNewPosition();
		checkNewPos = GetInstance()->_gameBoard->WrapPosition(checkNewPos);


		if (GetInstance()->_gameBoard->CellContainsConsumable(checkNewPos))
		{
			GetInstance()->_gameBoard->dataBoard[checkNewPos.first][checkNewPos.second]->SetActiveState(false);
			if (GetInstance()->_gameBoard->dataBoard[checkNewPos.first][checkNewPos.second]->GetEffect() == FreightMode)
			{
				ActivateFreightMode();
			}
			GetInstance()->_points += GetInstance()->_gameBoard->dataBoard[checkNewPos.first][checkNewPos.second]->GetPoints();
		}
		if (GetInstance()->_gameBoard->IsCellTraversible(checkNewPos))
		{
			GetInstance()->_gameBoard->RestoreCell(currentPos);   // restore what was there
			pacman.SetPosition(checkNewPos);
			GetInstance()->_gameBoard->ChangeCell(checkNewPos, 'P');
		}
		else 
		{
			pacman.SetDirection(previousDir);
		}

		for (auto& ghost : GetInstance()->_ghosts) {
			if (!ghost->IsActive()) continue;
			ghost->ChooseRandomDirection();          // pick a new random direction
			auto ghostCurrent = ghost->GetPosition();
			auto ghostNew = ghost->TryGetNewPosition();
			ghostNew = GetInstance()->_gameBoard->WrapPosition(ghostNew);

			if (GetInstance()->_gameBoard->IsCellTraversible(ghostNew)) { // check board externally
				GetInstance()->_gameBoard->RestoreCell(ghostCurrent);
				ghost->SetPosition(ghostNew);
				if (GetInstance()->_freightMode) LOG(BLUE);
				GetInstance()->_gameBoard->ChangeCell(ghostNew, 'G');
				LOG(RESET_COLORS);
			}

			if (ghost->GetPosition() == pacman.GetPosition())
			{
				if (GetInstance()->_freightMode)
				{
					Sleep(50);
					GetInstance()->_points += 200 * GetInstance()->_freightMultiplier;
					GetInstance()->_freightMultiplier *= 2;
					ghost->SetPosition(GetInstance()->_ghostHome);
					ghost->KillGhost();
				}
				else
				{
					// Kill pacman
					Sleep(2000);
					pacman.SetPosition(GetInstance()->_pacmanStartPos);
					pacman.OnDeath();

					if (pacman.GetLives() <= 0)
					{
						StartMenu();
						return;
					}
				}
			}
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(50));
	}
	TickManager::GetInstance()->StopAutoTick();
}

void GameManager::EndGame()
{
	// Handle Game Ending
	// Call delete on all dynamically created objects

}

GameManager* GameManager::GetInstance()
{
	if (_sInstance) return _sInstance;

	_sInstance = new GameManager();
	return _sInstance;
}

void GameManager::ActivateFreightMode()
{
	GetInstance()->_freightMode = true;
	GetInstance()->_freightModeTimer = GetInstance()->_freightModeDuration;
}

void GameManager::Tick(float deltaTime)
{
	if (_freightMode)
	{
		_freightModeTimer -= deltaTime;
		if (_freightModeTimer <= 0.0f)
		{
			_freightMode = false;
			_freightModeTimer = 0.0f;
			_freightMultiplier = 1;
		}
	}
}

int GameManager::GetPoints()
{
	return _points;
}


// Menu Graphics

void MenuGraphics::StartMenuStart()
{
	LOG_LN("============================");
	LOG_LN(WHITE_BG << "          Start           " << RESET_COLORS);
	LOG_LN("============================");
	LOG_LN("          Exit              ");
	LOG_LN("============================");
	LOG_LN("Points: " << GameManager::GetInstance()->GetPoints());

}

void MenuGraphics::StartMenuExit()
{
	LOG_LN("============================");
	LOG_LN("          Start           ");
	LOG_LN("============================");
	LOG_LN(WHITE_BG << "          Exit              " << RESET_COLORS);
	LOG_LN("============================");
	LOG_LN("Points: " << GameManager::GetInstance()->GetPoints());


}

void MenuGraphics::PauseContinue()
{
	LOG_LN("============================");
	LOG_LN(WHITE_BG << "         Continue           " << RESET_COLORS);
	LOG_LN("============================");
	LOG_LN("         Restart            ");
	LOG_LN("============================");
	LOG_LN("          Exit              ");
	LOG_LN("============================");
	LOG_LN("Points: " << GameManager::GetInstance()->GetPoints());

}

void MenuGraphics::PauseRestart()
{
	LOG_LN("============================");
	LOG_LN("         Continue           ");
	LOG_LN("============================");
	LOG_LN(WHITE_BG << "         Restart            " << RESET_COLORS);
	LOG_LN("============================");
	LOG_LN("          Exit              ");
	LOG_LN("============================");
	LOG_LN("Points: " << GameManager::GetInstance()->GetPoints());

}

void MenuGraphics::PauseExit()
{
	LOG_LN("============================");
	LOG_LN("         Continue           ");
	LOG_LN("============================");
	LOG_LN("         Restart            ");
	LOG_LN("============================");
	LOG_LN(WHITE_BG << "          Exit              " << RESET_COLORS);
	LOG_LN("============================");
	LOG_LN("Points: " << GameManager::GetInstance()->GetPoints());

}
