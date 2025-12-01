#include "microDouble.h"
#include <stdint.h>
#include <stdio.h>
#include <string.h>

void runAllTests();

int getBit(const Number* n, int i)
{
    int byteIndex = i / 8;
    int bitIndex = 7 - (i % 8);
    return (n->bytes[byteIndex] >> bitIndex) & 1;
}

int theMain()
{
    Number num;
    scanf("%lf", &num.value);
    uint64_t bits = num.bits;
    int sign = (bits >> 63) & 1;
    int exponent = (bits >> 52) & 0x7FF;
    uint64_t mantissa_bits = bits & 0xFFFFFFFFFFFFF;

    if (exponent == 0x7FF) {
        if (mantissa_bits == 0) {
            printf("Result: %cinf\n", sign ? '-' : '+');
        } else {
            printf("Result: nan\n");
        }
        return 0;
    }

    if (exponent == 0 && mantissa_bits == 0) {
        printf("Result: %c0*2^0\n", sign ? '-' : '+');
        return 0;
    }

    double mantissa = 0;
    int exp = 0;

    if (exponent == 0) {
        mantissa = (double)mantissa_bits / (1ULL << 52);
        exp = -1022;

        while (mantissa < 1.0) {
            mantissa *= 2.0;
            exp--;
        }
    } else {
        mantissa = 1.0 + (double)mantissa_bits / (1ULL << 52);
        exp = exponent - 1023;

        if (mantissa >= 2.0) {
            mantissa /= 2.0;
            exp++;
        } else if (mantissa < 1.0) {
            mantissa *= 2.0;
            exp--;
        }
    }

    printf("Result: %c%.18g*2^%d\n", sign ? '-' : '+', mantissa, exp);
    return 0;
}

int main(int arg, char* argv[])
{
    if (arg == 2 && strcmp(argv[1], "--tests") == 0) {
        runAllTests();
        return 0;
    }
    theMain();
    return 0;
}
