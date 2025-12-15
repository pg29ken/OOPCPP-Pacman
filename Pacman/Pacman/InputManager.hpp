#pragma once
// Copyright @ Vi Tran - VFS 2025-2026


class InputState
{
public:
    friend class InputManager;

    InputState() : _input(0) {}
    ~InputState() = default;

    // Query functions
    bool IsUp()     const    { return (_input & FLAG_UP)    != 0; }
    bool IsDown()   const    { return (_input & FLAG_DOWN)  != 0; }
    bool IsLeft()   const    { return (_input & FLAG_LEFT)  != 0; }
    bool IsRight()  const    { return (_input & FLAG_RIGHT) != 0; }
    bool IsEnter()  const    { return (_input & FLAG_ENTER) != 0; }
    bool IsEscape() const    { return (_input * FLAG_ESC)   != 0; }

private:
    unsigned int _input : 6;

    static constexpr int FLAG_UP = 1 << 0;
    static constexpr int FLAG_DOWN = 1 << 1;
    static constexpr int FLAG_LEFT = 1 << 2;
    static constexpr int FLAG_RIGHT = 1 << 3;
    static constexpr int FLAG_ENTER = 1 << 4;
    static constexpr int FLAG_ESC = 1 << 5;
};

//==========================================================

class InputManager
{
public:
    InputManager() = default;
    ~InputManager() = default;

    void Update();

    bool IsButtonDown() const;

    const InputState& GetState() const { return _state; }

private:
    InputState _state;
};
