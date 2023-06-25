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

    Trie ()
    {
        const char *alphabet = "abcdefghijklmnopqrstuvwxyz";

        while (*alphabet)
            roots.push (Leaf { *alphabet++, {} });
    }

    void push (string str)
    {
        Leaf *leaf  = nullptr;
        u32   index = 0;

        for (u32 i = 0; i < roots.length () && !leaf; i++)
            if (roots[i].data == str[0])
                leaf = &roots[i];

        bool found;

        for (index = 1; index < str.length (); index++)
        {
            found = false;

            for (u32 i = 0; i < leaf->children.length (); i++)
            {
                if (leaf->children[i].data == str[index])
                {
                    leaf  = &leaf->children[i];
                    found = true;
                    break;
                }
            }

            if (!found)
                break;
        }

        if (index != str.length ())
            for (; index < str.length (); index++)
                leaf = leaf->children.push (Leaf { str[index], {} });
    }

    Leaf *findRoot (char c)
    {
        for (u32 i = 0; i < roots.length (); i++)
            if (roots[i].data == c)
                return &roots[i];

        return nullptr;
    }

    Leaf *findLeaf (Leaf &leaf, char c)
    {
        for (Leaf &children : leaf.children)
            if (children.data == c)
                return &children;

        return nullptr;
    }

    void goDeep (array<string> &arr, string &s, Leaf &leaf)
    {
        string copy ((const char *)s.c_str ());

        copy.push (leaf.data);

        if (leaf.children.length () > 0)
            for (u32 i = 0; i < leaf.children.length (); i++)
                goDeep (arr, copy, leaf.children[i]);
        else
            arr.push (copy);
    }

    array<string> getCandidates (string str)
    {
        u32 i = 0;

        Leaf         *leaf = findRoot (str[i++]);
        array<string> result;

        for (; i < str.length () && leaf; i++)
            leaf = findLeaf (*leaf, str[i]);

        if (leaf)
        {
            string n (str.c_str ());

            for (u32 i = 0; i < leaf->children.length (); i++)
                goDeep (result, n, leaf->children[i]);
        }

        return result;
    }
};

#endif
