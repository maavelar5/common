#ifndef AVLTREE
#define AVLTREE

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

#endif
