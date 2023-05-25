#ifndef API
#define API

#define SDL

#include "typedefs.hpp"
#include <cstdarg>

namespace api
{
    void stdout (const char* str, va_list args);
    void errout (const char* str, va_list args);
    void debout (const char* str, va_list args);

    uint32 getTicks ();
}

#ifdef SDL
#include "sdl_api.hpp"
#endif

#endif
