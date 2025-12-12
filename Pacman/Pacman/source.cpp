#include <iostream>
#include <windows.h>
#include "Utils.hpp"
#include "InputManager.hpp"
#include "Board.hpp"
#include "Entity.hpp"
int main()
{
    InputManager inputMgr;
    Board board;
    Entity pacman = Entity("Pacman", {26, 13});

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

            if (state.IsUp()) pacman.SetDirection(MoveDirection::UP);
            else if (state.IsDown())  pacman.SetDirection(MoveDirection::DOWN);
            else if (state.IsLeft())  pacman.SetDirection(MoveDirection::LEFT);
            else if (state.IsRight()) pacman.SetDirection(MoveDirection::RIGHT);

            if (GetAsyncKeyState('Q') & 0x8000)
                running = false;

            LOG_LN(pacman.GetDirection());
            // call pacman.move
            // call ghost.move
        }

        time++;
    }

    LOG_LN("Exiting...\n");
    return 0;
}
