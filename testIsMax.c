#include "isMax.h"
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

void testConvertToNumber()
{

    bool arr1[8] = { false, false, false, false, false, false, false, false };
    assert(convertToNumber(arr1, 8) == 0);
    printf("pass\n");

    bool arr2[8] = { true, true, true, true, true, true, true, true };
    assert(convertToNumber(arr2, 8) == 255);
    printf("pass\n");

    bool arr3[8] = { false, false, false, false, false, false, false, true };
    assert(convertToNumber(arr3, 8) == 1);
    printf("pass\n");
}

void testIntegration()
{
    bool first[8] = { true, false, false, true, true, true, false, false };
    bool second[8] = { true, false, false, false, false, true, false, true };

    int num1 = convertToNumber(first, 8);
    int num2 = convertToNumber(second, 8);

    assert(num1 == 156);
    assert(num2 == 133);

    bool arr3[8] = { false, false, false, false, false, false, false, true };
    bool arr4[8] = { true, false, false, false, false, false, false, false };

    int num3 = convertToNumber(arr3, 8);
    int num4 = convertToNumber(arr4, 8);

    assert(num3 == 1);
    assert(num4 == 128);
    assert(num4 > num3);

    printf("pass\n");
}

void runAllTests()
{
    testConvertToNumber();
    testIntegration();

    printf("All tests pass");
}
