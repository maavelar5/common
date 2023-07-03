#include "../def/typedefs.hpp"

size_t CURR_MEM_SIZE = 0;

void* operator new (size_t size)
{
    CURR_MEM_SIZE++;
    return malloc (size);
}

void operator delete (void* ptr) noexcept
{
    free (ptr);
    CURR_MEM_SIZE++;
}
