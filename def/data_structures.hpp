#ifndef DATASTRUCTURES
#define DATASTRUCTURES

#include <cassert>
#include "typedefs.hpp"

#include "array.hpp"
#include "list.hpp"
#include "avltree.hpp"
#include "trie.hpp"

template <typename Type, uint32 M, uint32 N> struct Matrix
{
    Type data[M][N];
};

template <typename Type, typename... Types>
array<Type> unique (Type val, Types... rest)
{
    array<Type> result;

    unique (result, val, rest...);

    return result;
}

template <typename Type, typename... Types>
void unique (array<Type> &result, Type val, Types... rest)
{
    unique (result, val);
    unique (result, rest...);
}

template <typename Type> void unique (array<Type> &unique, Type val)
{
    for (uint32 i = 0; i < unique.length (); i++)
        if (unique[i] == val)
            return;

    unique.push (val);
}

template <class V1, class V2> struct Tuple
{
    struct Data
    {
        V1 v1;
        V2 v2;
    };

    array<Data> values;
};

template <class Key, class Val> struct HashTable
{
    struct Cell
    {
        Key  key;
        Val  value;
        bool filled;
    };

    Cell        end;
    array<Cell> arr;

    HashTable ()
    {
        end = { 0, 0, 0 };
    }

    int getKey (Key key)
    {
        return (arr.size () == 0) ? -1 : key & arr.size ();
    }

    Cell &find (Key key)
    {
        int id = getKey (key);

        if (id == -1)
            return end;
        else if (arr[id].filled == false)
            return end;
        else
            return arr[id];
    }
};

#endif
