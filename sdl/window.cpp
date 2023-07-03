#include "SDL.h"
#include "GL/glew.h"
#include "GL/gl.h"

#include "../def/window.hpp"

u32           sdlFlags = 0;
SDL_Window   *window   = nullptr;
SDL_GLContext context  = nullptr;

Window::Window ()
{
    flags = 0;
    pos = prevPos = size = { 0, 0 };
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

    sdlFlags = SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL;

    window = SDL_CreateWindow (name, pos.x, pos.y, size.w, size.h, sdlFlags);

    if (window == NULL)
    {
        SDL_LogError (SDL_LOG_CATEGORY_APPLICATION, "%s", SDL_GetError ());
        exit (1);
    }

    context = SDL_GL_CreateContext (window);

    if (context == NULL)
    {
        SDL_LogError (SDL_LOG_CATEGORY_APPLICATION, "%s", SDL_GetError ());
        exit (1);
    }

    GLenum ok = glewInit ();

    if (ok != GLEW_OK)
    {
        SDL_LogError (SDL_LOG_CATEGORY_APPLICATION, "%s",
                      glewGetErrorString (ok));
        exit (1);
    }
}

void Window::move (v2s newPos)
{
    prevPos = pos;

    SDL_SetWindowPosition (window, newPos.x, newPos.y);
    SDL_GetWindowPosition (window, &pos.x, &pos.y);
}

void Window::clear (Color color)
{
    glClearColor (color.r / 255.f, color.g / 255.f, color.b / 255.f,
                  color.a / 255.f);
    glClear (GL_COLOR_BUFFER_BIT);
}

void Window::draw (v4u shit)
{
}
