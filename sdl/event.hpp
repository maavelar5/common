#ifndef COMMON_SDL_EVENT
#define COMMON_SDL_EVENT

#include "../event.hpp"
#include "SDL.h"

namespace api
{
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

}

bool Event::getNext (Event &event)
{
    SDL_Event e;

    if (SDL_PollEvent (&e))
    {
        if (e.type == SDL_MOUSEBUTTONDOWN)
        {
            event.type         = Device::MOUSE;
            event.mouse.action = Action::PRESS;
            event.mouse.button = api::getMouseButton (e.button.button);
        }
        else if (e.type == SDL_KEYDOWN)
        {
            event.type            = Device::KEYBOARD;
            event.keyboard.key    = api::getKey (e.key.keysym.sym);
            event.keyboard.action = Action::PRESS;
        }
        else if (e.type == SDL_MOUSEBUTTONUP)
        {
            event.type         = Device::MOUSE;
            event.mouse.action = Action::RELEASE;
            event.mouse.button = api::getMouseButton (e.button.button);
        }
        else if (e.type == SDL_KEYUP)
        {
            event.type            = Device::KEYBOARD;
            event.keyboard.key    = api::getKey (e.key.keysym.sym);
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

void Event::push (Event &e)
{
    SDL_Event event;

    switch (e.type)
    {
        case Device::KEYBOARD:
            if (e.keyboard.action == Action::PRESS)
                event.type = SDL_KEYDOWN;
            else
                event.type = SDL_KEYUP;

            event.key.keysym.sym = api::getKey (e.keyboard.key);

            SDL_PushEvent (&event);
            break;
        case Device::QUIT:
            event.type = SDL_QUIT;
            SDL_PushEvent (&event);
            break;
        default: event.type = SDL_FIRSTEVENT; break;
    }
}

#endif
