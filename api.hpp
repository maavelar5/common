#ifndef API
#define API

#define SDL

#include <cstdarg>
#include "memory.hpp"
#include "typedefs.hpp"
#include "math_data.hpp"
#include "file.hpp"

struct Event;
struct Window;
struct Renderer;

namespace api
{
    void stdout (const char* str, va_list args);
    void errout (const char* str, va_list args);
    void debout (const char* str, va_list args);
    void initVideo ();

    uint32 getTicks ();
}

#ifdef SDL
#include "sdl/sdl.hpp"
#endif

#endif
