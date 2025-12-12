#include <iostream>
#include <windows.h>
#include "Utils.hpp"
#include "InputManager.hpp"
#include "Board.hpp"
int main()
{
    InputManager inputMgr;
    Board board;

    LOG_LN("Press arrow keys (UP, DOWN, LEFT, RIGHT). Press 'Q' to quit.\n");
    board.RenderBoard();

    bool running = true;
    int time = 0;
    while (running)
    {
        if (time % 40000000 == 0)
        {
            inputMgr.Update();

            const InputState& state = inputMgr.GetState();

            if (state.IsUp())    LOG_LN("UP\n");
            // change pacman direction to up
            else if (state.IsDown())  LOG_LN("DOWN\n");
            // change pacman direction to down
            else if (state.IsLeft())  LOG_LN("LEFT\n");
            // change pacman direction to left
            else if (state.IsRight()) LOG_LN("RIGHT\n");
            // change pacman direction to right

            if (GetAsyncKeyState('Q') & 0x8000)
                running = false;


            // call pacman.move
            // call ghost.move
        }

        time++;
    }

    LOG_LN("Exiting...\n");
    return 0;
}
