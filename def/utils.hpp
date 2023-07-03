#ifndef UTILS
#define UTILS

#include <cassert>
#include <cstdlib>

#include "typedefs.hpp"
#include "math_data.hpp"

struct Color
{
    u8 r, g, b, a;
    v4 norm;
};

enum RGBA
{
    RED   = 0xff000000,
    GREEN = 0x00ff0000,
    BLUE  = 0x0000ff00,
    ALPHA = 0x000000ff,
};

uint8 HexToInt (char c)
{
    if (c >= '0' && c <= '9')
        return c - '0';
    else if (c >= 'a' && c <= 'f')
        return 10 + (c - 'a');
    else
        return 0;
}

Color Hex (const char hex[10])
{
    return Color {
        (uint8)(HexToInt (hex[1]) * 16 + HexToInt (hex[2])),
        (uint8)(HexToInt (hex[3]) * 16 + HexToInt (hex[4])),
        (uint8)(HexToInt (hex[5]) * 16 + HexToInt (hex[6])),
        (uint8)(HexToInt (hex[7]) * 16 + HexToInt (hex[8])),
    };
}

#endif
