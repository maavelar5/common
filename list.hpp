#ifndef LIST
#define LIST

template <class Type> class list
{
    struct Node
    {
        Type val;

        Node *next, *prev;
    };

    Node *first, *last;

  public:
    list ()
    {
        first = last = nullptr;
    }

    template <typename... Types> list (Type var1, Types... var2)
    {
        first = last = nullptr;

        push (var1, var2...);
    }

    template <typename... Types> void push (Type var1, Types... var2)
    {
        push (var1);
        push (var2...);
    }

    void push (Type val)
    {
        Node *node = new Node {
            .val  = val,
            .next = nullptr,
            .prev = nullptr,
        };

        if (!first)
        {
            first = node;
        }
        else
        {
            last->next = node;
            node->prev = last;
        }

        last = node;
    }

    Node *remove (Node *it)
    {
        Node *node = it;

        it = it->next;

        if (node == first)
        {
            if (first == last)
                first = last = nullptr;
            else
            {
                first       = first->next;
                first->prev = nullptr;
            }
        }
        else if (node == last)
        {
            last       = last->prev;
            last->next = nullptr;
        }
        else
        {
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }

        delete node;

        return it;
    }

    void remove (Type val)
    {
        Node *it = first;

        while (it)
            it = (it->val == val) ? remove (it) : it->next;
    }

    typedef bool (*compareFn) (const Type a, const Type b);
    void remove (Type val, compareFn fn)
    {
        Node *it = first;

        while (it)
            it = fn (*it, val) ? remove (it) : it->next;
    }

    void clean ()
    {
        while (first)
            remove (first);
    }

    typedef void (*forEachFn) (Type &val);
    void forEach (forEachFn fn)
    {
        Node *it = first;

        while (it)
        {
            fn (it->val);

            it = it->next;
        }
    }

    struct iterator
    {
        Node *node;

        const Node *operator++ ()
        {
            node = node->next;
            return node;
        }

        bool operator!= (iterator &it)
        {
            return (node != it.node) ? true : false;
        }

        Type &operator* ()
        {
            return node->val;
        }
    };

    typedef const iterator *const_iterator;

    iterator begin ()
    {
        return iterator { first };
    }

    const_iterator begin () const
    {
        return iterator { first };
    }
    iterator end ()
    {
        return iterator { last };
    }
    const_iterator end () const
    {
        return iterator { last };
    }
};

#endif
