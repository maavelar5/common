#ifndef SDL_API
#define SDL_API

#include "SDL.h"
#include "video.hpp"
#include "typedefs.hpp"
#include "event.hpp"

#include "SDL_opengl.h"

namespace api
{
    SDL_Window   *sdlWindow   = nullptr;
    SDL_Renderer *sdlRenderer = nullptr;
    SDL_GLContext glContext   = nullptr;

    // SDL_GL_GetProcAddress ("laksjdlfksaj");
    char *readFile (const char *filename)
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

    void stdout (const char *str, va_list args)
    {
        SDL_LogMessageV (SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO,
                         str, args);
    }

    void errout (const char *str, va_list args)
    {
        SDL_LogMessageV (SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR,
                         str, args);
    }
    void debout (const char *str, va_list args)
    {
        SDL_LogMessageV (SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_DEBUG,
                         str, args);
    }

    void critical ()
    {
        SDL_LogCritical (SDL_LOG_CATEGORY_VIDEO, "[MARCO][CRITICAL] %s",
                         SDL_GetError ());

        exit (1);
    }

    uint32 getTicks ()
    {
        return SDL_GetTicks ();
    }

    void initVideo ()
    {
        if (SDL_Init (SDL_INIT_EVERYTHING) != 0)
            critical ();
    }

    Window createWindow (const char *name, v2s pos, v2s size, u8 flags)
    {
        assert (sdlWindow == nullptr);

        Window window = {
            pos, size, pos, flags, string (name),
        };

        u32 windowFlags = SDL_WINDOW_SHOWN;

        if (flags == OPENGL)
            windowFlags |= SDL_WINDOW_OPENGL;

        sdlWindow = SDL_CreateWindow (name, pos.x, pos.y, size.w, size.h,
                                      windowFlags);

        if (!sdlWindow)
            critical ();

        return window;
    }

    void move (Window &window, v2s pos)
    {
        SDL_SetWindowPosition (sdlWindow, pos.x, pos.y);
        window.prevPos = window.pos;
        SDL_GetWindowPosition (sdlWindow, &window.pos.x, &window.pos.y);
    }

    bool nextEvent (Event &event)
    {
        SDL_Event e;

        if (SDL_PollEvent (&e))
        {
            if (e.type == SDL_MOUSEBUTTONDOWN)
            {
                event.type = EventDevice::MOUSE;

                switch (e.button.button)
                {
                    case SDL_BUTTON_LEFT:
                        event.mouse.button = MouseButton::LEFT;
                        break;
                    case SDL_BUTTON_RIGHT:
                        event.mouse.button = MouseButton::RIGHT;
                        break;
                    case SDL_BUTTON_MIDDLE:
                        event.mouse.button = MouseButton::MIDDLE;
                        break;
                    case SDL_BUTTON_X1:
                        event.mouse.button = MouseButton::PREV;
                        break;
                    case SDL_BUTTON_X2:
                        event.mouse.button = MouseButton::NEXT;
                        break;
                }

                event.mouse.press = PressEvent::PRESS;
            }
            else if (e.type == SDL_KEYDOWN)
            {
                switch (e.key.keysym.sym)
                {
                }
            }

            return true;
        }
        else
        {
            return false;
        }
    }
}

#endif
