#include <iostream>
#include <windows.h>
#include "Utils.hpp"
#include "TickManager.hpp"
#include "InputManager.hpp"
#include "GameManager.hpp"

int main()
{
    InputManager inputMgr;

    LOG_LN("Press arrow keys (UP, DOWN, LEFT, RIGHT). Press 'Q' to quit.\n");

    bool running = true;
    int time = 0;

    TickObject A;
    TickObject B;
    TickObject C;
    TickManager::GetInstance()->StartAutoTick(1000);
    GameManager::GetInstance()->PauseGame();
    TickManager::GetInstance()->StopAutoTick();
    //std::cout << "Ticking : " << this << std::endl;

    LOG_LN("Exiting...\n");
    return 0;
}
