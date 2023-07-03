#ifndef WINDOW
#define WINDOW

#include "string.hpp"
#include "typedefs.hpp"
#include "math_data.hpp"
#include "utils.hpp"

enum WindowFlags
{
    SHOWN = 1
};

struct Window
{
    v2s    pos, size, prevPos;
    u32    flags;
    string name;

    Window ();
    Window (const char* name, v2s pos, v2s size, u8 flags);

    void move (v2s pos);
    void draw (v4u color);
    void init (const char* name, v2s pos, v2s size, u8 flags);
    void clear (Color color);
};

#endif
