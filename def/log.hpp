#ifndef LOG
#define LOG

#include <cstring>
#include "api.hpp"

void log (const char* fmt, ...);
void debug (const char* fmt, ...);
void error (const char* msg);

#endif
