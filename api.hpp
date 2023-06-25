#ifndef API
#define API

#define SDL

#include <cstdarg>
#include "memory.hpp"
#include "typedefs.hpp"
#include "math_data.hpp"

struct Event;
struct Window;
struct Renderer;

namespace api
{
    char* readFile (const char* filename);

    File readSPV (const char* filename);

    void stdout (const char* str, va_list args);
    void errout (const char* str, va_list args);
    void debout (const char* str, va_list args);

    uint32 getTicks ();

    void initVideo ();

    void     move (Window& window, v2s pos);
    Window   createWindow (const char* name, v2s pos, v2s size, u8 flags);
    Renderer createRenderer ();

    bool getNextEvent (Event& e);
    void pushEvent (Event& e);
}

#ifdef SDL
#include "sdl_api.hpp"
#endif

#endif
