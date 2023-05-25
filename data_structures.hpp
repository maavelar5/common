#ifndef DATASTRUCTURES
#define DATASTRUCTURES

#include <cassert>
#include "log.hpp"

enum class Alloc
{
    RESIZE
};

const Alloc alloc = Alloc::RESIZE;

template <class Type> struct array
{
    Type  *data;
    uint32 length, size;

    array ()
    {
        data   = 0;
        length = size = 0;
    }

    array (Alloc, uint32 size)
    {
        data   = new Type[this->size = size];
        length = size;
    }

    template <typename... Types> array (Type var1, Types... var2)
    {
        data = 0;
        size = length = 0;

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
        data[length++] = val;

        return &data[length - 1];
    }

    void remove (uint32 index)
    {
        assert (index < length);

        for (uint32 i = index; i < length - 1; i++)
            data[i] = data[i + 1];

        length--;
    }

    void resize ()
    {
        if (size == 0)
        {
            data = new Type[size = 1];
        }
        else if (length >= size)
        {
            Type *data = new Type[size *= 2];

            for (uint32 i = 0; i < length; i++)
                data[i] = this->data[i];

            delete[] this->data;

            this->data = data;
        }
    }

    void resize (uint32 newSize)
    {
        assert (newSize > 0);

        if (size == 0)
        {
            data   = new Type[size = newSize];
            length = newSize;
        }
        else if (newSize > length)
        {
            Type *data = new Type[size = newSize];

            for (uint32 i = 0; i < length; i++)
                data[i] = this->data[i];

            delete[] this->data;

            length     = size;
            this->data = data;
        }
        else
        {
            length = size = newSize;
        }
    }

    Type &operator[] (uint32 index)
    {
        return at (index);
    }

    Type &at (uint32 index)
    {
#ifdef DEBUG
        if (index >= length)
            debug ("[ASSERT] index: %d -- length: %d", index, length);
#endif

        assert (index < length);

        return data[index];
    }

    typedef void (*fn) (Type &t);
    void forEach (fn callback)
    {
        for (uint32 i = 0; i < length; i++)
            callback (data[i]);
    }

    bool equals (const array<Type> &arr)
    {
        for (uint32 i = 0; i < length; i++)
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
        return &data[length];
    }
    const_iterator end () const
    {
        return &data[length];
    }

    void clean ()
    {
        if (size > 0)
            delete[] data;

        data = nullptr;
        size = length = 0;
    }
};

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
    for (uint32 i = 0; i < unique.length; i++)
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

template <class T> struct AVLTree
{
    struct Leaf
    {
        T     val;
        Leaf *left, *right;
    };

    Leaf *root_;

    AVLTree ()
    {
        root_ = nullptr;
    }

    template <typename... Types> AVLTree (T val, Types... rest)
    {
        push (val, rest...);
    }

    template <typename... Types> void push (T val, Types... rest)
    {
        push (val);
        push (rest...);
    }

    void push (T val)
    {
        Leaf *node = new Leaf { val, nullptr, nullptr };

        if (!root_)
        {
            root_ = node;
        }
        else
        {
            Leaf *leaf = find (root_, val);

            if (val < leaf->val)
                leaf->left = node;
            else
                leaf->right = node;

            balance (root_, nullptr);
        }
    }

    Leaf *balance (Leaf *leaf, Leaf *parent = nullptr)
    {
        int   left = height (leaf->left), right = height (leaf->right);
        Leaf *result = nullptr, **side = &root_;

        if (parent)
        {
            if (parent->left == leaf)
                side = &parent->left;
            else if (parent->right == leaf)
                side = &parent->right;

            assert (side != &root_);
        }

        if (left - right < -1)
        {
            if (leaf->right->right)
                result = leftRotate (leaf);
            else
                result = rightLeftRotate (leaf);

            *side = result;
        }
        else if (left - right > 1)
        {
            if (leaf->left->left)
                result = rightRotate (leaf);
            else
                result = leftRightRotate (leaf);

            *side = result;
        }

        if (leaf->left)
            balance (leaf->left, leaf);
        if (leaf->right)
            balance (leaf->right, leaf);

        return nullptr;
    }

    Leaf *findParent (Leaf *leaf, Leaf *node)
    {
        if (node == root_)
            return root_;

        if (node->val < leaf->val)
            return (leaf->left == node) ? leaf : findParent (leaf->left, node);
        else
            return (leaf->right == node) ? leaf
                                         : findParent (leaf->right, node);
    }

    Leaf *find (Leaf *leaf, T val)
    {
        assert (leaf != nullptr);

        if (val < leaf->val)
            return (!leaf->left) ? leaf : find (leaf->left, val);
        else
            return (!leaf->right) ? leaf : find (leaf->right, val);
    }

    Leaf *leftRotate (Leaf *a)
    {
        Leaf *b = a->right;

        a->right = b->left;
        b->left  = a;

        return b;
    }

    Leaf *rightRotate (Leaf *a)
    {
        Leaf *b = a->left;

        a->left  = b->right;
        b->right = a;

        return b;
    }

    Leaf *rightLeftRotate (Leaf *a)
    {
        Leaf *c = a->right;
        Leaf *b = c->left;

        a->right = b;
        c->left  = b->right;
        b->right = c;

        a->right = b->left;
        b->left  = a;

        return b;
    }

    Leaf *leftRightRotate (Leaf *a)
    {
        Leaf *b = a->left;
        Leaf *c = b->right;

        b->right = c->left;
        a->left  = c;
        c->left  = b;

        a->left  = c->right;
        c->right = a;

        return c;
    }

    void insert (Leaf *root, Leaf *leaf)
    {
        if (leaf->val < root->val)
        {
            if (!root->left)
                root->left = leaf;
            else
                insert (root->left, leaf);
        }
        else if (leaf->val >= root->val)
        {
            if (!root->right)
                root->right = leaf;
            else
                insert (root->right, leaf);
        }
    }

    void print (Leaf *leaf)
    {
        log ("%d\n", leaf->val);

        if (leaf->left)
            log ("left: %d\n", leaf->left->val);
        if (leaf->right)
            log ("right: %d\n", leaf->right->val);

        if (leaf->left)
            print (leaf->left);

        if (leaf->right)
            print (leaf->right);
    }

    int height (Leaf *root)
    {
        if (!root)
            return 0;

        int left = 0, right = 0, max = 0;

        if (root->right)
            right = height (root->right);

        if (root->left)
            left = height (root->left);

        max = (left > right) ? left : right;

        return max + 1;
    }

    void clean (Leaf *leaf)
    {
        if (leaf->left)
            clean (leaf->left);
        if (leaf->right)
            clean (leaf->right);

        free (leaf);
    }

    void clean ()
    {
        clean (root_);

        root_ = nullptr;
    }
};

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

        nullTerminatedPtr = new char[arr.length + 1];

        uint32 i = 0;

        for (; i < arr.length; i++)
            nullTerminatedPtr[i] = arr.data[i];

        nullTerminatedPtr[arr.length] = '\0';

        return nullTerminatedPtr;
    }

    void clean ()
    {
        if (nullTerminatedPtr)
            delete nullTerminatedPtr;
        if (arr.data)
            delete arr.data;
    }

    char &operator[] (uint32 index)
    {
        return arr[index];
    }

    uint32 length ()
    {
        return arr.length;
    }
};

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
        Leaf  *leaf  = nullptr;
        uint32 index = 0;

        for (uint32 i = 0; i < roots.length && !leaf; i++)
            if (roots[i].data == str[0])
                leaf = &roots[i];

        bool found;

        for (index = 1; index < str.arr.length; index++)
        {
            found = false;

            for (uint32 i = 0; i < leaf->children.length; i++)
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

        if (index == str.arr.length)
            log ("this was already added, dumbass");
        else
            for (; index < str.arr.length; index++)
                leaf = leaf->children.push (Leaf { str[index], {} });
    }

    Leaf *findRoot (char c)
    {
        for (uint32 i = 0; i < roots.length; i++)
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
        string copy ((const char *)s.nullTerminated ());

        copy.push (leaf.data);

        if (leaf.children.length > 0)
            for (uint32 i = 0; i < leaf.children.length; i++)
                goDeep (arr, copy, leaf.children[i]);
        else
            arr.push (copy);
    }

    array<string> getCandidates (string str)
    {
        uint32 i = 0;

        Leaf         *leaf = findRoot (str[i++]);
        array<string> result;

        for (; i < str.arr.length && leaf; i++)
            leaf = findLeaf (*leaf, str[i]);

        if (leaf)
        {
            string n (str.nullTerminated ());

            for (uint32 i = 0; i < leaf->children.length; i++)
                goDeep (result, n, leaf->children[i]);
        }

        return result;
    }
};

#endif
