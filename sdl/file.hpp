#ifndef COMMON_SDL_FILE
#define COMMON_SDL_FILE

#include "SDL.h"
#include "../file.hpp"

void File::read (const char *filename)
{
    SDL_RWops *rw = SDL_RWFromFile (filename, "rb");

    if (rw == NULL)
        return;

    size    = SDL_RWsize (rw);
    content = new char[size + 1];

    sint64 nb_read_total = 0, nb_read = 1;
    char  *buf = content;

    while (nb_read_total < size && nb_read != 0)
    {
        nb_read = SDL_RWread (rw, buf, 1, (size - nb_read_total));
        nb_read_total += nb_read;
        buf += nb_read;
    }

    SDL_RWclose (rw);

    if (nb_read_total != size)
    {
        delete[] content;
        return;
    }

    content[nb_read_total] = '\0';
}

void File::readSPV (const char *filename)
{
    SDL_RWops *rw = SDL_RWFromFile (filename, "rb");

    if (rw == NULL)
        return;

    size    = SDL_RWsize (rw);
    content = new char[size + 1];

    sint64 nb_read_total = 0, nb_read = 1;
    char  *buf = content;

    while (nb_read_total < size && nb_read != 0)
    {
        nb_read = SDL_RWread (rw, buf, 1, (size - nb_read_total));
        nb_read_total += nb_read;
        buf += nb_read;
    }

    SDL_RWclose (rw);

    if (nb_read_total != size)
    {
        delete[] content;
        return;
    }
}

#endif
