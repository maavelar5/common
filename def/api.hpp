#ifndef API
#define API

#define SDL

#include <cstdarg>
#include "typedefs.hpp"

namespace api
{
    void stdout (const char* str, va_list args);
    void errout (const char* str, va_list args);
    void debout (const char* str, va_list args);
    void initVideo ();

    uint32 getTicks ();
}

#endif
