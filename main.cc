#include "testcases.hpp"

int main (int argc, char **argv)
{
    runTestCases ();
    assert (CURR_MEM_SIZE == 0);
    return 0;
}
