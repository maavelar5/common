#ifndef STRING
#define STRING

#include "array.hpp"

struct string
{
    char       *cstr;
    array<char> arr;

    string ();
    string (const char *str);

    ~string ();

    void push (char c);
    void push (const char *str);

    void        clean ();
    const char *c_str ();

    char &operator[] (u32 index);

    u32 length ();
};

#endif
