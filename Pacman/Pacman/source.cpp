#include <iostream>
#include <windows.h> // For Sleep
#include "Utils.hpp"
#include "InputManager.hpp"

int main()
{
    InputManager inputMgr;

    LOG_LN("Press arrow keys (UP, DOWN, LEFT, RIGHT). Press 'Q' to quit.\n");

    bool running = true;

    while (running)
    {
        inputMgr.Update();

        const InputState& state = inputMgr.GetState();

        if (state.IsUp())    std::cout << "UP\n";
        else if (state.IsDown())  std::cout << "DOWN\n";
        else if (state.IsLeft())  std::cout << "LEFT\n";
        else if (state.IsRight()) std::cout << "RIGHT\n";

        if (GetAsyncKeyState('Q') & 0x8000)
            running = false;
    }

    LOG_LN("Exiting...\n");
    return 0;
}
