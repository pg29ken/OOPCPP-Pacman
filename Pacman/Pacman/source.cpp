#include <iostream>
#include <windows.h>
#include "Utils.hpp"
#include "TickManager.hpp"
#include "InputManager.hpp"
#include "GameManager.hpp"
#include "Board.hpp"
#include "Pacman.hpp"

int main()
{
    InputManager inputMgr;
    // BOard
    Pacman player;
    // gamemanager


    GameManager::GetInstance()->StartMenu();
    //GameManager::GetInstance()->PauseGame();
    
    //std::cout << "Ticking : " << this << std::endl;

    LOG_LN("Exiting...\n");
    return 0;
}
