#ifndef MEMORY
#define MEMORY

#include "typedefs.hpp"

#define KB(I) (I * 1024)
#define MB(I) (KB (I) * 1024)
#define GB(I) (MB (I) * 1024)

struct Chunk
{
    u32    size;
    u8     bytes[KB (32)];
    Chunk *next;
};

u8 *getBytes (Chunk *chunk, u32 howManyBytes)
{
    u8 *result = (chunk->bytes + chunk->size);
    chunk->size += howManyBytes;
    return result;
}

Chunk chunk = { 0, 0, 0 };

struct ChunkGroup
{
    Chunk *first;
};

struct String
{
    char *thing;
    u32   length;

    void push (const char *cstr)
    {
        while (*cstr)
            thing[length++] = *(cstr++);
    }
};

String NewString (u32 size)
{
    return {
        (char *)getBytes (&chunk, size),
        0,
    };
}

#endif
