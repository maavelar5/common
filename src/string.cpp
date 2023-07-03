#include "../def/string.hpp"

string::string ()
{
    cstr = nullptr;
}

string::string (const char *str)
{
    cstr = nullptr;
    push (str);
}

string::~string ()
{
    arr.clean ();

    if (cstr)
        delete cstr;
}

void string::push (const char *str)
{
    assert (str != nullptr);

    while (*str)
        arr.push (*str++);
}

void string::push (char c)
{
    arr.push (c);
}

const char *string::c_str ()
{
    if (cstr)
        delete cstr;

    cstr = new char[arr.length () + 1];

    u32 i = 0;

    for (; i < arr.length (); i++)
        cstr[i] = arr[i];

    cstr[arr.length ()] = '\0';

    return cstr;
}

void string::clean ()
{
    if (cstr)
        delete cstr;
    arr.clean ();
}

char &string::operator[] (u32 index)
{
    return arr[index];
}

u32 string::length ()
{
    return arr.length ();
}
