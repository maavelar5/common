#ifndef RENDERER
#define RENDERER

#include "math_data.hpp"
#include "data_structures.hpp"
#include "utils.hpp"

struct Renderer
{
    Color fg, bg;

    static Renderer create ();
};

#endif
