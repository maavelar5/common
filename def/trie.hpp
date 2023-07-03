#ifndef TRIE
#define TRIE

#include "string.hpp"
#include "array.hpp"

struct Trie
{
    struct Leaf
    {
        char        data;
        array<Leaf> children;
    };

    array<Leaf> roots;

    Trie ();

    void push (string str);
    void goDeep (array<string> &arr, string &s, Leaf &leaf);

    Leaf *findRoot (char c);
    Leaf *findLeaf (Leaf &leaf, char c);

    array<string> getCandidates (string str);
};

#endif
