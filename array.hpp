#ifndef ARRAY
#define ARRAY

#include <cassert>
#include "typedefs.hpp"

enum class Alloc
{
    RESIZE
};

const Alloc alloc = Alloc::RESIZE;

template <class Type> class array
{
    Type *data;
    u32   _length, _size;

  public:
    array ()
    {
        data    = 0;
        _length = _size = 0;
    }

    array (Alloc, u32 size)
    {
        data    = new Type[_size = size];
        _length = _size;
    }

    template <typename... Types> array (Type var1, Types... var2)
    {
        data  = 0;
        _size = _length = 0;

        push (var1, var2...);
    }

    template <typename... Types> void push (Type var1, Types... var2)
    {
        push (var1);
        push (var2...);
    }

    Type *push (Type val)
    {
        resize ();
        data[_length++] = val;

        return &data[_length - 1];
    }

    void remove (u32 index)
    {
        assert (index < _length);

        for (u32 i = index; i < _length - 1; i++)
            data[i] = data[i + 1];

        _length--;
    }

    void resize ()
    {
        if (_size == 0)
        {
            data = new Type[_size = 1];
        }
        else if (_length >= _size)
        {
            Type *data = new Type[_size *= 2];

            for (u32 i = 0; i < _length; i++)
                data[i] = this->data[i];

            delete[] this->data;

            this->data = data;
        }
    }

    void resize (u32 newSize)
    {
        assert (newSize > 0);

        if (_size == 0)
        {
            data    = new Type[_size = newSize];
            _length = newSize;
        }
        else if (newSize > _length)
        {
            Type *data = new Type[_size = newSize];

            for (u32 i = 0; i < _length; i++)
                data[i] = this->data[i];

            delete[] this->data;

            _length    = _size;
            this->data = data;
        }
        else
        {
            _length = _size = newSize;
        }
    }

    Type &operator[] (u32 index)
    {
        return at (index);
    }

    Type &at (u32 index)
    {
        assert (index < _length);

        return data[index];
    }

    typedef void (*fn) (Type &t);
    void forEach (fn callback)
    {
        for (u32 i = 0; i < _length; i++)
            callback (data[i]);
    }

    bool equals (const array<Type> &arr)
    {
        for (u32 i = 0; i < _length; i++)
            if (data[i] != arr.data[i])
                return false;

        return true;
    }

    typedef Type       *iterator;
    typedef const Type *const_iterator;

    iterator begin ()
    {
        return &data[0];
    }

    const_iterator begin () const
    {
        return &data[0];
    }
    iterator end ()
    {
        return &data[_length];
    }
    const_iterator end () const
    {
        return &data[_length];
    }

    void reset ()
    {
        _length = (_size > 0) ? 1 : 0;
    }

    void clean ()
    {
        if (_size > 0)
            delete[] data;

        data  = nullptr;
        _size = _length = 0;
    }

    u32 length ()
    {
        return _length;
    }

    u32 size ()
    {
        return _size;
    }
};

#endif
