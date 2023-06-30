#ifndef LOG
#define LOG

#include <cstring>
#include "api.hpp"

#define STR_SIZE 4096

void log (const char* fmt, ...)
{
    static char str[STR_SIZE];

    strcpy (str, "[MARCO]: ");
    strcat (str, fmt);

    va_list args;

    va_start (args, fmt);
    api::stdout (str, args);
    va_end (args);
}

void debug (const char* fmt, ...)
{
#ifdef DEBUG
    static char str[STR_SIZE];

    strcpy (str, "[MARCO][DEBUG]: ");
    strcat (str, fmt);

    va_list args;

    va_start (args, fmt);
    api::debout (str, args);
    va_end (args);
#endif
}

void error (const char* msg)
{
    static char str[STR_SIZE];

    strcpy (str, "[MARCO][ERROR]: ");

    if (msg)
        strcat (str, msg);

    api::errout (str, nullptr);

    exit (1);
}

#endif
