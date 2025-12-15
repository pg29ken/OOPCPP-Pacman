// Copyright @ Ken Arigo - VFS 2025-2026

#pragma once
#include "Utils.hpp"

class GameManager
{
	// Holds reference to systems
	
public:
	static void StartMenu();
	static void PauseGame();
	//static void WinScreen();

	static void StartGame();
	static void EndGame();

	static GameManager* GetInstance();

private:
	static GameManager* _sInstance;
	int _points;

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