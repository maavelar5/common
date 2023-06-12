#ifndef STRING
#define STRING

#include "array.hpp"

struct string
{
    char       *nullTerminatedPtr;
    array<char> arr;

    string ()
    {
        nullTerminatedPtr = nullptr;
    }

    string (const char *str)
    {
        nullTerminatedPtr = nullptr;
        push (str);
    }

    void push (const char *str)
    {
        assert (str != nullptr);

        while (*str)
            arr.push (*str++);
    }

    void push (char c)
    {
        arr.push (c);
    }

    const char *nullTerminated ()
    {
        if (nullTerminatedPtr)
            delete nullTerminatedPtr;

        nullTerminatedPtr = new char[arr.length () + 1];

        u32 i = 0;

        for (; i < arr.length (); i++)
            nullTerminatedPtr[i] = arr[i];

        nullTerminatedPtr[arr.length ()] = '\0';

        return nullTerminatedPtr;
    }

    void clean ()
    {
        if (nullTerminatedPtr)
            delete nullTerminatedPtr;
        arr.clean ();
    }

    char &operator[] (u32 index)
    {
        return arr[index];
    }

    u32 length ()
    {
        return arr.length ();
    }
};

#endif
