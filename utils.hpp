#ifndef UTILS
#define UTILS

#include <cassert>
#include <cstdlib>

#include "SDL.h"
#include "log.hpp"

static char *readFile (const char *filename)
{
    SDL_RWops *rw = SDL_RWFromFile (filename, "rb");

    if (rw == NULL)
        return NULL;

    sint64 res_size = SDL_RWsize (rw);
    char  *res      = (char *)malloc (res_size + 1);

    sint64 nb_read_total = 0, nb_read = 1;
    char  *buf = res;

    while (nb_read_total < res_size && nb_read != 0)
    {
        nb_read = SDL_RWread (rw, buf, 1, (res_size - nb_read_total));
        nb_read_total += nb_read;
        buf += nb_read;
    }

    SDL_RWclose (rw);

    if (nb_read_total != res_size)
    {
        free (res);
        return NULL;
    }

    res[nb_read_total] = '\0';

    return res;
}

struct File
{
    uint32 size;
    char  *content;
};

File readSPV (const char *filename)
{
    SDL_RWops *rw = SDL_RWFromFile (filename, "rb");

    if (rw == NULL)
        return { 0, 0 };

    sint64 res_size = SDL_RWsize (rw);
    char  *res      = (char *)malloc (res_size + 1);

    sint64 nb_read_total = 0, nb_read = 1;
    char  *buf = res;

    while (nb_read_total < res_size && nb_read != 0)
    {
        nb_read = SDL_RWread (rw, buf, 1, (res_size - nb_read_total));
        nb_read_total += nb_read;
        buf += nb_read;
    }

    SDL_RWclose (rw);

    if (nb_read_total != res_size)
    {
        free (res);
        return { 0, 0 };
    }

    return { (uint32)res_size, res };
}

struct Color
{
    uint8 r, g, b, a;

    void print ()
    {
        log ("%d - %d - %d - %d\n", r, g, b, a);
    }
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
