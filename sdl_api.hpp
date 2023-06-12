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

    SDL_Keycode getKey (Key key)
    {
        switch (key)
        {
            case Key::a: return SDLK_a; break;
            case Key::b: return SDLK_b; break;
            case Key::c: return SDLK_c; break;
            case Key::d: return SDLK_d; break;
            case Key::e: return SDLK_e; break;
            case Key::f: return SDLK_f; break;
            case Key::g: return SDLK_g; break;
            case Key::h: return SDLK_h; break;
            case Key::i: return SDLK_i; break;
            case Key::j: return SDLK_j; break;
            case Key::k: return SDLK_k; break;
            case Key::l: return SDLK_l; break;
            case Key::m: return SDLK_m; break;
            case Key::n: return SDLK_n; break;
            case Key::o: return SDLK_o; break;
            case Key::p: return SDLK_p; break;
            case Key::q: return SDLK_q; break;
            case Key::r: return SDLK_r; break;
            case Key::s: return SDLK_s; break;
            case Key::t: return SDLK_t; break;
            case Key::u: return SDLK_u; break;
            case Key::v: return SDLK_v; break;
            case Key::w: return SDLK_w; break;
            case Key::x: return SDLK_x; break;
            case Key::y: return SDLK_y; break;
            case Key::z: return SDLK_z; break;
            default: return SDLK_UNKNOWN;
        }
    }

    Key getKey (SDL_Keycode kc)
    {
        switch (kc)
        {
            case SDLK_a: return Key::a; break;
            case SDLK_b: return Key::b; break;
            case SDLK_c: return Key::c; break;
            case SDLK_d: return Key::d; break;
            case SDLK_e: return Key::e; break;
            case SDLK_f: return Key::f; break;
            case SDLK_g: return Key::g; break;
            case SDLK_h: return Key::h; break;
            case SDLK_i: return Key::i; break;
            case SDLK_j: return Key::j; break;
            case SDLK_k: return Key::k; break;
            case SDLK_l: return Key::l; break;
            case SDLK_m: return Key::m; break;
            case SDLK_n: return Key::n; break;
            case SDLK_o: return Key::o; break;
            case SDLK_p: return Key::p; break;
            case SDLK_q: return Key::q; break;
            case SDLK_r: return Key::r; break;
            case SDLK_s: return Key::s; break;
            case SDLK_t: return Key::t; break;
            case SDLK_u: return Key::u; break;
            case SDLK_v: return Key::v; break;
            case SDLK_w: return Key::w; break;
            case SDLK_x: return Key::x; break;
            case SDLK_y: return Key::y; break;
            case SDLK_z: return Key::z; break;
            default: return Key::UNKNOWN;
        }
    }

    MouseButton getMouseButton (u8 button)
    {
        switch (button)
        {
            case SDL_BUTTON_LEFT: return MouseButton::LEFT; break;
            case SDL_BUTTON_RIGHT: return MouseButton::RIGHT; break;
            case SDL_BUTTON_MIDDLE: return MouseButton::MIDDLE; break;
            case SDL_BUTTON_X1: return MouseButton::PREV; break;
            case SDL_BUTTON_X2: return MouseButton::NEXT; break;
            default: return MouseButton::UNKNOWN; break;
        }
    }

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

        return { (u32)res_size, res };
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

    u32 getTicks ()
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
        if (sdlWindow != nullptr)
            SDL_DestroyWindow (sdlWindow);

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

    bool getNextEvent (Event &event)
    {
        SDL_Event e;

        if (SDL_PollEvent (&e))
        {
            if (e.type == SDL_MOUSEBUTTONDOWN)
            {
                event.type         = Device::MOUSE;
                event.mouse.action = Action::PRESS;
                event.mouse.button = getMouseButton (e.button.button);
            }
            else if (e.type == SDL_KEYDOWN)
            {
                event.type            = Device::KEYBOARD;
                event.keyboard.key    = getKey (e.key.keysym.sym);
                event.keyboard.action = Action::PRESS;
            }
            else if (e.type == SDL_MOUSEBUTTONUP)
            {
                event.type         = Device::MOUSE;
                event.mouse.action = Action::RELEASE;
                event.mouse.button = getMouseButton (e.button.button);
            }
            else if (e.type == SDL_KEYUP)
            {
                event.type            = Device::KEYBOARD;
                event.keyboard.key    = getKey (e.key.keysym.sym);
                event.keyboard.action = Action::RELEASE;
            }
            else if (e.type == SDL_MOUSEMOTION)
            {
                event.type         = Device::MOUSE;
                event.mouse.action = Action::MOTION;

                event.mouse.pos = {
                    e.motion.x,
                    e.motion.y,
                };
            }
            else if (e.type == SDL_QUIT)
            {
                event.type = Device::QUIT;
            }
            else
            {
                event.type = Device::UNKNOWN;
            }

            return true;
        }
        else
        {
            return false;
        }
    }

    void pushEvent (Event &e)
    {
        SDL_Event event;

        switch (e.type)
        {
            case Device::KEYBOARD:
                if (e.keyboard.action == Action::PRESS)
                    event.type = SDL_KEYDOWN;
                else
                    event.type = SDL_KEYUP;

                event.key.keysym.sym = getKey (e.keyboard.key);

                SDL_PushEvent (&event);
                break;
            case Device::QUIT:
                event.type = SDL_QUIT;
                SDL_PushEvent (&event);
                break;
            default: event.type = SDL_FIRSTEVENT; break;
        }
    }
}

#endif
