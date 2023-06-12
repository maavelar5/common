#ifndef EVENT
#define EVENT

#include "math_data.hpp"

enum class Device
{
    UNKNOWN = 0,
    MOUSE   = 1,
    TOUCH,
    GAMEPAD,
    KEYBOARD,

    QUIT,
};

enum class Action
{
    PRESS = 1,
    RELEASE,
    MOTION,
};

enum class MouseButton
{
    UNKNOWN = 0,
    LEFT    = 1,
    RIGHT,
    MIDDLE,
    NEXT,
    PREV,
};

enum class Key
{
    UNKNOWN = 0,

    a,
    b,
    c,
    d,
    e,
    f,
    g,
    h,
    i,
    j,
    k,
    l,
    m,
    n,
    o,
    p,
    q,
    r,
    s,
    t,
    u,
    v,
    w,
    x,
    y,
    z,

    ALT,
    CTRL,
    SUPER,
    SHIFT,
};

struct MouseEvent
{
    v2s         pos;
    Action      action;
    MouseButton button;
};

struct KeyboardEvent
{
    Key    key;
    uint8  repeat;
    Action action;
};

struct Event
{
    Device type;

    union
    {
        MouseEvent    mouse;
        KeyboardEvent keyboard;
    };
};

#endif
