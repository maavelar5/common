#ifndef TESTCASES
#define TESTCASES

#include "dataStructures.hpp"
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

    assert (set.length == 6);

    delete set.data;

    set = unique (0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    assert (set[0] == 0);
    assert (set.length == 1);
}

void testArray ()
{
    array<int> arr = { 1, 1, 2, 2, 3, 3, 5, 5, 6 };

    assert (arr.length == 9);
    assert (arr.size == 16);

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

    assert (arr.length == 1);
    assert (arr.size == 1);

    array<int> arr2 (alloc, 20);

    assert (arr2.length == 20 && arr2.size == 20);

    array<int *> arr3 (alloc, 30);

    assert (arr3.length == 30 && arr3.size == 30);
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
    results.length = expected.length = 0;

    expected.push (6, 2, 1, 0, 4, 3, 5, 10, 8, 7, 9, 15, 11, 22, 33);
    tree.push (4, 6, 5, 3, 1, 2, 10, 9, 7, 11, 15, 0, 8, 22, 33);

    bnTreeTest (tree.root_, results);

    assert (expected.equals (results));

    tree.clean ();
    results.length = expected.length = 0;

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

    assert (strcmp (results[0].nullTerminated (), "anci") == 0);
    assert (strcmp (results[1].nullTerminated (), "anyi") == 0);
    assert (strcmp (results[2].nullTerminated (), "anpi") == 0);
    assert (strcmp (results[3].nullTerminated (), "anxi") == 0);
    assert (strcmp (results[4].nullTerminated (), "apci") == 0);
    assert (strcmp (results[5].nullTerminated (), "apce") == 0);

    results.clean ();

    results = trie.getCandidates (string ("ap"));

    assert (strcmp (results[0].nullTerminated (), "apci") == 0);
    assert (strcmp (results[1].nullTerminated (), "apce") == 0);

    results.clean ();

    results = trie.getCandidates (string ("en"));
    assert (strcmp (results[0].nullTerminated (), "enci") == 0);
    assert (strcmp (results[1].nullTerminated (), "enyi") == 0);
    assert (strcmp (results[2].nullTerminated (), "enpi") == 0);
    assert (strcmp (results[3].nullTerminated (), "enxi") == 0);

    results.clean ();
}

#define RunTest(fn) \
    fn ();          \
    debug (#fn " => success");

void runTestCases ()
{
    log ("Running test cases");

    RunTest (testUnique);
    RunTest (testArray);
    RunTest (testAVL);
    RunTest (testTrie);
}

#endif
