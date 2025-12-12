#include "InputManager.hpp"
#include <windows.h>
#include "EventHandler.hpp"

EventHandler::EventHandler()
{
}

void EventHandler::TickFunction()
{

}

void InputManager::Update()
{
    _state._input = 0;

    if (GetAsyncKeyState(VK_UP) & 0x8000)
    {
        _state._input |= InputState::FLAG_UP;
    }
    else if (GetAsyncKeyState(VK_DOWN) & 0x8000)
    {
        _state._input |= InputState::FLAG_DOWN;
    }
    else if (GetAsyncKeyState(VK_LEFT) & 0x8000)
    {
        _state._input |= InputState::FLAG_LEFT;
    }
    else if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
    {
        _state._input |= InputState::FLAG_RIGHT;
    }
}

bool InputManager::IsButtonDown() const
{
    return _state._input != 0;
}
