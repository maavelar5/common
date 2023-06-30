#ifndef COMMON_SDL_WINDOW
#define COMMON_SDL_WINDOW

#include "SDL.h"
#include "../window.hpp"

SDL_Window   *window   = nullptr;
SDL_Renderer *renderer = nullptr;
SDL_GLContext context  = nullptr;

Window::Window ()
{
    pos = prevPos = size = { 0, 0 };
    flags                = 0;
}

Window::Window (const char *name, v2s pos, v2s size, u8 flags) : Window ()
{
    init (name, pos, size, flags);
}

void Window::init (const char *name, v2s pos, v2s size, u8 flags)
{
    if (window != nullptr)
        SDL_DestroyWindow (window);

    this->size  = size;
    this->flags = flags;
    prevPos = this->pos = pos;

    this->name.push (name);

    u32 windowFlags = SDL_WINDOW_SHOWN;

    if (flags == OPENGL)
        windowFlags |= SDL_WINDOW_OPENGL;

    window = SDL_CreateWindow (name, pos.x, pos.y, size.w, size.h, windowFlags);
}

void Window::move (v2s newPos)
{
    prevPos = pos;

    SDL_SetWindowPosition (window, newPos.x, newPos.y);
    SDL_GetWindowPosition (window, &pos.x, &pos.y);
}

#endif
