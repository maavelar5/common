#ifndef WINDOW
#define WINDOW

#include "string.hpp"
#include "typedefs.hpp"
#include "math_data.hpp"

enum WindowFlags
{
    OPENGL = 1,
    SOFTWARE,
};

struct Window
{
    v2s    pos, size, prevPos;
    u32    flags;
    string name;

    Window ();
    Window (const char* name, v2s pos, v2s size, u8 flags);

    void move (v2s pos);
    void init (const char* name, v2s pos, v2s size, u8 flags);
};

#endif
