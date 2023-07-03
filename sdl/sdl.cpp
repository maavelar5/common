#include "SDL.h"
#include "../def/typedefs.hpp"

namespace api
{
    // SDL_GL_GetProcAddress ("laksjdlfksaj");

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
}
