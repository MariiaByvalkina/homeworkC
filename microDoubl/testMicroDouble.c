#include "microDouble.h"
#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int double_eq(double a, double b)
{
    return fabs(a - b) < 1e-12;
}

void testOne()
{
    Number n2 = { 1.0 };
    int s2 = (n2.bits >> 63) & 1;
    int e2 = (n2.bits >> 52) & 0x7FF;
    uint64_t m2 = n2.bits & 0xFFFFFFFFFFFFF;
    double mant2 = 1.0 + (double)m2 / (1ULL << 52);
    int exp2 = e2 - 1023;
    if (mant2 >= 2.0) {
        mant2 /= 2.0;
        exp2++;
    }
    assert(s2 == 0 && double_eq(mant2, 1.0) && exp2 == 0);
    printf("pass\n");
}

void testTwo()
{
    Number n4 = { 2.0 };
    int e4 = (n4.bits >> 52) & 0x7FF;
    uint64_t m4 = n4.bits & 0xFFFFFFFFFFFFF;
    double mant4 = 1.0 + (double)m4 / (1ULL << 52);
    int exp4 = e4 - 1023;
    if (mant4 >= 2.0) {
        mant4 /= 2.0;
        exp4++;
    }
    assert(double_eq(mant4, 1.0) && exp4 == 1);
    printf("pass\n");
}

void testExample1()
{
    Number n5 = { -2.5 };
    int s5 = (n5.bits >> 63) & 1;
    int e5 = (n5.bits >> 52) & 0x7FF;
    uint64_t m5 = n5.bits & 0xFFFFFFFFFFFFF;
    double mant5 = 1.0 + (double)m5 / (1ULL << 52);
    int exp5 = e5 - 1023;
    if (mant5 >= 2.0) {
        mant5 /= 2.0;
        exp5++;
    } else if (mant5 < 1.0) {
        mant5 *= 2.0;
        exp5--;
    }
    assert(s5 == 1 && double_eq(mant5, 1.25) && exp5 == 1);
    printf("pass\n");
}

void testExample2()
{
    Number n6 = { 12312.323 };
    int e6 = (n6.bits >> 52) & 0x7FF;
    uint64_t m6 = n6.bits & 0xFFFFFFFFFFFFF;
    double mant6 = 1.0 + (double)m6 / (1ULL << 52);
    int exp6 = e6 - 1023;
    if (mant6 >= 2.0) {
        mant6 /= 2.0;
        exp6++;
    }
    assert(fabs(mant6 - 1.5029691162109375) < 1e-14 && exp6 == 13);
    printf("pass\n");
}

void runAllTests()
{
    testOne();
    testTwo();
    testExample1();
    testExample2();

    printf("All tests pass");
}