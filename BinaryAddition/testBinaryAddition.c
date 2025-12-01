#include "binaryAddition.h"
#include <assert.h>
#include <stdio.h>

void testPositiveNumbers()
{
    addInColumn(10, 20);
    assert(10 + 20 == 30);
    printf("pass\n");
}

void testNegativeNumbers()
{
    addInColumn(-5, -3);
    assert(-5 + -3 == -8);
    printf("pass\n");
}

void testMixedNumbers()
{
    addInColumn(15, -7);
    assert(15 + -7 == 8);
    printf("pass\n");
}

void testZero()
{
    addInColumn(0, 25);
    assert(0 + 25 == 25);
    printf("pass\n");
}

void runBinaryTests()
{

    testPositiveNumbers();
    testNegativeNumbers();
    testMixedNumbers();
    testZero();

    printf("All tests pass");
}
