// Copyright @ Ken Arigo - VFS 2025-2026

#include "GameManager.hpp"
#include "TickManager.hpp"	
#include "InputManager.hpp"
#include "Board.hpp"
#include "Pacman.hpp"
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
				break;
			case 1:
				// Restart logic here
				inMenu = false;
				break;
			case 2:
				inMenu = false;
				StartMenu();
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
	InputManager inputManager;
	const InputState& state = inputManager.GetState();
	Board board;
	Pacman pacman;
	board.RenderBoard();
	board.ChangeCell(pacman.GetPosition(), 'p');

	TickManager::GetInstance()->StartAutoTick(1000);
	bool isGameRunning = true;
	while (isGameRunning) {
			//Pacman Input
		inputManager.Update();
		if (inputManager.IsButtonDown()) 
		{
			if (state.IsUp()) pacman.SetDirection(MoveDirection::UP);
			if (state.IsDown()) pacman.SetDirection(MoveDirection::DOWN);
			if (state.IsLeft()) pacman.SetDirection(MoveDirection::LEFT);
			if (state.IsRight()) pacman.SetDirection(MoveDirection::RIGHT);
		}
		std::pair<int, int>  currentPos = pacman.GetPosition();
		std::pair<int, int> checkNewPos = pacman.TryGetNewPosition();

		if (board.IsCellTraversible(checkNewPos))
		{
			board.RestoreCell(currentPos);   // restore what was there
			pacman.SetPosition(checkNewPos);
			board.ChangeCell(checkNewPos, 'P');
		}
		if (board.CellContainsConsumable(checkNewPos))
		{
			board.dataBoard[checkNewPos.first][checkNewPos.second]->SetActiveState(false);
			board.dataBoard[checkNewPos.first][checkNewPos.second]->OnConsumed();
			GetInstance()->_points += board.dataBoard[checkNewPos.first][checkNewPos.second]->GetPoints();
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
}

void MenuGraphics::StartMenuExit()
{
	LOG_LN("============================");
	LOG_LN("          Start           ");
	LOG_LN("============================");
	LOG_LN(WHITE_BG << "          Exit              " << RESET_COLORS);
	LOG_LN("============================");
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
}
