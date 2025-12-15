// Copyright @ Ken Arigo - VFS 2025-2026

#pragma once
#include "Utils.hpp"
#include "Board.hpp"	

class GameManager : TickObject
{
	// Holds reference to systems
	
public:
	static void StartMenu();
	static void PauseGame();
	//static void WinScreen();

	static void StartGame();
	static void EndGame();

	static GameManager* GetInstance();
	static void ActivateFreightMode();

	int GetPoints();

private:
	std::vector<Ghost*> _ghosts;

	static GameManager* _sInstance;
	int _points;

	std::atomic_bool _freightMode = false;
	float _freightModeTimer = 0.0f;
	const float _freightModeDuration = 8.0f;
	int _freightMultiplier = 1;

	bool _isGameRunning = false;

	std::pair<int, int> _pacmanStartPos = { 26,15 };
	std::pair<int, int> _ghostHome = { 11,13 };
	Board* _gameBoard;

	void Tick(float deltaTime) override;
};


class MenuGraphics
{
	friend class GameManager;

	// Pause Menus

private:

	static void StartMenuStart();
	static void StartMenuExit();

	static void PauseContinue();
	static void PauseRestart();
	static void PauseExit();
};