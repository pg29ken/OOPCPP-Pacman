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
    LOG_LN("Press arrow keys (UP, DOWN, LEFT, RIGHT). Press 'Q' to quit.\n");


    GameManager::GetInstance()->StartGame();
    //GameManager::GetInstance()->PauseGame();
    
    //std::cout << "Ticking : " << this << std::endl;

    LOG_LN("Exiting...\n");
    return 0;
}
