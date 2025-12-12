#include <iostream>
#include <windows.h>
#include "Utils.hpp"
#include "InputManager.hpp"

int main()
{
    InputManager inputMgr;

    LOG_LN("Press arrow keys (UP, DOWN, LEFT, RIGHT). Press 'Q' to quit.\n");

    bool running = true;
    int time = 0;
    while (running)
    {
        if (time % 40000000 == 0)
        {
            inputMgr.Update();

            const InputState& state = inputMgr.GetState();

            if (state.IsUp())    LOG_LN("UP\n");
            else if (state.IsDown())  LOG_LN("DOWN\n");
            else if (state.IsLeft())  LOG_LN("LEFT\n");
            else if (state.IsRight()) LOG_LN("RIGHT\n");

            if (GetAsyncKeyState('Q') & 0x8000)
                running = false;

        }

        time++;
    }

    LOG_LN("Exiting...\n");
    return 0;
}
