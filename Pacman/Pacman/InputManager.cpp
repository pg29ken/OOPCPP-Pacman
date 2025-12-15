#include "InputManager.hpp"
#include <windows.h>
#include "EventHandler.hpp"

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
    if (GetAsyncKeyState(VK_RETURN) & 0x8000) 
    {
        _state._input |= InputState::FLAG_ENTER;
    }
    if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
    {
        _state._input |= InputState::FLAG_ESC;
    }
}

bool InputManager::IsButtonDown() const
{
    return _state._input != 0;
}
