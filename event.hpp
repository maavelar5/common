#ifndef EVENT
#define EVENT

#include "math_data.hpp"

enum class EventDevice
{
    MOUSE = 1,
    TOUCH,
    GAMEPAD,
    KEYBOARD,
};

enum class PressEvent
{
    PRESS = 1,
    RELEASE,
};

enum class MouseButton
{
    LEFT = 1,
    RIGHT,
    MIDDLE,
    NEXT,
    PREV,
    UNKNOWN,
};

enum class Key
{
    UNKNOWN = 0,

    A = 1,
    B,
    C,
    D,
    E,
    F,
    G,
    H,
    I,
    J,
    K,
    L,
    M,
    N,
    O,
    P,
    Q,
    R,
    S,
    T,
    U,
    V,
    W,
    X,
    Y,
    Z,

    ALT,
    CTRL,
    SUPER,
    SHIFT,
};

struct MouseEvent
{
    v2s         currPos, prevPos;
    PressEvent  press;
    MouseButton button;
};

struct KeyboardEvent
{
    Key        key;
    uint8      repeat;
    PressEvent event;
};

struct Event
{
    EventDevice type;

    union
    {
        MouseEvent    mouse;
        KeyboardEvent keyboard;
    };
};

#endif
