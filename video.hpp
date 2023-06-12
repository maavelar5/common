#ifndef VIDEO
#define VIDEO

#include "math_data.hpp"
#include "data_structures.hpp"
#include "utils.hpp"

enum WindowFlags
{
    OPENGL = 1,
    SOFTWARE,
    ACCELERATED,
};

struct Window
{
    v2s    pos, size, prevPos;
    u32    flags;
    string name;
};

struct Renderer
{
    Color bg;
};

#endif
