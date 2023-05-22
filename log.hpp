#ifndef LOG
#define LOG

#include <cstdint>
#include <cstring>

#define SDL
#define STR_SIZE 4096

typedef int32_t  sint32;
typedef int64_t  sint64;
typedef uint8_t  uint8;
typedef uint32_t uint32;

/*NOTE: These should be implemented. I'm in love with SDL so I use it
 * everywhere.*/

void log (const char* fmt, ...);
void debug (const char* fmt, ...);
void error (const char* msg = nullptr);

#ifdef SDL
#include "SDL.h"

void log (const char* fmt, ...)
{
    static char str[STR_SIZE];

    strcpy (str, "[MARCO]: ");
    strcat (str, fmt);

    va_list args;

    va_start (args, fmt);
    SDL_LogMessageV (SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, str,
                     args);
    va_end (args);
}

static void debug (const char* fmt, ...)
{
#ifdef DEBUG
    static char str[STR_SIZE];

    strcpy (str, "[MARCO][DEBUG]: ");
    strcat (str, fmt);

    va_list args;

    va_start (args, fmt);
    SDL_LogMessageV (SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, str,
                     args);
    va_end (args);
#endif
}

static void error (const char* msg = nullptr)
{
    static char str[STR_SIZE];

    strcpy (str, "[MARCO][ERROR]: ");

    if (msg)
        strcat (str, msg);
    else
        strcat (str, SDL_GetError ());

    SDL_LogError (SDL_LOG_CATEGORY_APPLICATION, "%s", str);

    exit (1);
}
#endif

#endif
