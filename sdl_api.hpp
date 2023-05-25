#ifndef SDL_API
#define SDL_API

#include "SDL.h"
#include "typedefs.hpp"

namespace api
{
    void stdout (const char* str, va_list args)
    {
        SDL_LogMessageV (SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO,
                         str, args);
    }
    void errout (const char* str, va_list args)
    {
        SDL_LogMessageV (SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR,
                         str, args);
    }
    void debout (const char* str, va_list args)
    {
        SDL_LogMessageV (SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_DEBUG,
                         str, args);
    }

    uint32 getTicks ()
    {
        return SDL_GetTicks ();
    }
}

#endif
