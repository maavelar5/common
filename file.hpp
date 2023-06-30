#ifndef FILE_
#define FILE_

#include "typedefs.hpp"

struct File
{
    u32   size;
    char* content;

    void read (const char* filename);
    void readSPV (const char* filename);
};

#endif
