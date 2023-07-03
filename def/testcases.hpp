#ifndef TESTCASES
#define TESTCASES

#include "api.hpp"
#include "data_structures.hpp"
#include "math_data.hpp"
#include "log.hpp"

void testUnique ()
{
    array<int> set
        = unique (1, 1, 1, 2, 2, 2, 3, 4, 5, 6, 6, 6, 1, 1, 2, 2, 3, 3);

    assert (set[0] == 1);
    assert (set[1] == 2);
    assert (set[2] == 3);
    assert (set[3] == 4);
    assert (set[4] == 5);
    assert (set[5] == 6);

    assert (set.length () == 6);

    set.clean ();

    set = unique (0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    assert (set[0] == 0);
    assert (set.length () == 1);
}

void testArray ()
{
    array<int> arr = { 1, 1, 2, 2, 3, 3, 5, 5, 6 };

    assert (arr.length () == 9);
    assert (arr.size () == 16);

    assert (arr[0] == 1 && arr[1] == 1);
    assert (arr[2] == 2 && arr[3] == 2);
    assert (arr[4] == 3 && arr[5] == 3);
    assert (arr[6] == 5 && arr[7] == 5);
    assert (arr[8] == 6);

    arr.remove (0);

    assert (arr[0] == 1);
    assert (arr[1] == 2 && arr[2] == 2);
    assert (arr[3] == 3 && arr[4] == 3);
    assert (arr[5] == 5 && arr[6] == 5);
    assert (arr[7] == 6);

    arr.remove (7);

    assert (arr[0] == 1);
    assert (arr[1] == 2 && arr[2] == 2);
    assert (arr[3] == 3 && arr[4] == 3);
    assert (arr[5] == 5 && arr[6] == 5);

    arr.remove (2);

    assert (arr[0] == 1);
    assert (arr[1] == 2);
    assert (arr[2] == 3 && arr[3] == 3);
    assert (arr[4] == 5 && arr[5] == 5);

    arr.resize (1);

    assert (arr.length () == 1);
    assert (arr.size () == 1);

    array<int> arr2 (alloc, 20);

    assert (arr2.length () == 0 && arr2.size () == 20);

    array<int *> arr3 (alloc, 30);

    assert (arr3.length () == 0 && arr3.size () == 30);
}

typedef void (*callback) (AVLTree<int>::Leaf *leaf, array<int> &results);

void bnTreeTest (AVLTree<int>::Leaf *leaf, array<int> &results)
{
    results.push (leaf->val);

    if (leaf->left)
        bnTreeTest (leaf->left, results);

    if (leaf->right)
        bnTreeTest (leaf->right, results);
};

void testAVL ()
{
    AVLTree<int> tree;

    tree.push (4, 6, 5, 3, 1, 2);

    array<int> expected (4, 2, 1, 3, 5, 6);
    array<int> results;

    bnTreeTest (tree.root_, results);

    assert (expected.equals (results));

    tree.clean ();
    results.reset ();
    expected.reset ();

    expected.push (6, 2, 1, 0, 4, 3, 5, 10, 8, 7, 9, 15, 11, 22, 33);
    tree.push (4, 6, 5, 3, 1, 2, 10, 9, 7, 11, 15, 0, 8, 22, 33);

    bnTreeTest (tree.root_, results);

    assert (expected.equals (results));

    tree.clean ();
    results.reset ();
    expected.reset ();

    expected.push (3, 2, 1, 5, 4, 6);
    tree.push (2, 1, 3, 5, 6, 4);

    bnTreeTest (tree.root_, results);

    assert (expected.equals (results));
}

void testTrie ()
{
    Trie trie;

    trie.push (string { "anci" });
    trie.push (string { "apci" });
    trie.push (string { "apce" });
    trie.push (string { "anyi" });
    trie.push (string { "anpi" });
    trie.push (string { "anxi" });

    trie.push (string { "enci" });
    trie.push (string { "epci" });
    trie.push (string { "epce" });
    trie.push (string { "enyi" });
    trie.push (string { "enpi" });
    trie.push (string { "enxi" });

    array<string> results = trie.getCandidates (string ("a"));

    assert (strcmp (results[0].c_str (), "anci") == 0);
    assert (strcmp (results[1].c_str (), "anyi") == 0);
    assert (strcmp (results[2].c_str (), "anpi") == 0);
    assert (strcmp (results[3].c_str (), "anxi") == 0);
    assert (strcmp (results[4].c_str (), "apci") == 0);
    assert (strcmp (results[5].c_str (), "apce") == 0);

    results.clean ();

    results = trie.getCandidates (string ("ap"));

    assert (strcmp (results[0].c_str (), "apci") == 0);
    assert (strcmp (results[1].c_str (), "apce") == 0);

    results.clean ();

    results = trie.getCandidates (string ("en"));
    assert (strcmp (results[0].c_str (), "enci") == 0);
    assert (strcmp (results[1].c_str (), "enyi") == 0);
    assert (strcmp (results[2].c_str (), "enpi") == 0);
    assert (strcmp (results[3].c_str (), "enxi") == 0);

    results.clean ();
}

void testv2 ()
{
    v2 result = v2 { 1, 2 } + v2 { 5, 6 };

    assert (result.x == 6 && result.y == 8);

    result = result - v2 { 5, 7 };

    assert (result.x == 1 && result.y == 1);

    result = result * v2 { 10, 10 };

    assert (result.x == 10 && result.y == 10);

    result = result / v2 { 10, 10 };

    assert (result.x == 1 && result.y == 1);
}

void testv3 ()
{
    v3 result = v3 { 1, 2, 4 } + v3 { 5, 6, 10 };

    assert (result.x == 6 && result.y == 8 && result.z == 14);

    result = result - v3 { 5, 7, 8 };

    assert (result.x == 1 && result.y == 1 && result.z == 6);

    result = result * v3 { 10, 10, 5 };

    assert (result.x == 10 && result.y == 10 && result.z == 30);

    result = result / v3 { 10, 10, 10 };

    assert (result.x == 1 && result.y == 1 && result.z == 3);
}

void testv4 ()
{
    v4 result = v4 { 1, 2, 4, 8 } + v4 { 5, 6, 10, 12 };

    assert (result.x == 6 && result.y == 8 && result.z == 14 && result.w == 20);

    result = result - v4 { 5, 7, 8, 10 };

    assert (result.x == 1 && result.y == 1 && result.z == 6 && result.w == 10);

    result = result * v4 { 10, 10, 5, 45 };

    assert (result.x == 10 && result.y == 10 && result.z == 30
            && result.w == 450);

    result = result / v4 { 10, 10, 10, 5 };

    assert (result.x == 1 && result.y == 1 && result.z == 3 && result.w == 90);
}

void testWindow ()
{
    Window window ("aslkdjfkl", v2s { 0, 0 }, v2s { 320, 320 }, SHOWN);

    window.move (v2s { 0, 0 });

    assert (window.pos == (v2s { 0, 0 }));
}

void testList ()
{
    int        i      = 0;
    list<int>  values = { 0, 1, 2, 3, 4 };
    array<int> result = { 0, 1, 2, 3, 4 };

    for (auto v : values)
    {
        assert (result[i] == v);
        i++;
    }

    i = 0;
    values.remove (values.begin ().node);
    result.remove (0);

    for (auto v : values)
        assert (result[i++] == v);

    i = 0;
    values.remove (values.end ().node);
    result.remove (3);

    for (auto v : values)
        assert (result[i++] == v);

    i = 0;
    values.remove (2);
    result.remove (1);

    for (auto v : values)
        assert (result[i++] == v);

    // for-range ref changes
    for (auto &v : values)
        v += 10;
    for (auto &v : result)
        v += 10;

    i = 0;
    for (auto v : values)
        assert (v == result[i++]);
}

void testEvents ()
{
    Window w ("ok", { 0, 0 }, { 320, 320 }, 0);

    array<Key>   expected, result;
    array<Event> events;

    Event myEvent = {
        .type = Device::KEYBOARD,
        .keyboard {
            Key::UNKNOWN,
            0,
            Action::PRESS,
        },
    };

    for (int i = 0; i < (int)Key::z; i++)
    {
        events.push (myEvent);
        expected.push ((Key)i);
        myEvent.keyboard.key = (Key)(i + 1);
    }

    myEvent.type = Device::QUIT;

    events.push (myEvent);

    for (auto e : events)
        Event::push (e);

    Event e;
    bool  run = true;

    while (run)
    {
        while (Event::getNext (e))
        {
            switch (e.type)
            {
                case Device::QUIT: run = false; break;
                case Device::KEYBOARD: result.push (e.keyboard.key); break;
                default: break;
            }
        }
    }

    for (int i = 0; i < expected.length (); i++)
        assert (expected[i] == result[i]);
}

#define RunTest(fn)          \
    log (#fn " => started"); \
    fn ();                   \
    log (#fn " => success");

void runTestCases ()
{
    log ("Running test cases");

    RunTest (testUnique);
    RunTest (testArray);
    RunTest (testAVL);
    RunTest (testTrie);
    RunTest (testv2);
    RunTest (testv3);
    RunTest (testv4);
    RunTest (testWindow);
    RunTest (testList);
    RunTest (testEvents);
}

#endif
