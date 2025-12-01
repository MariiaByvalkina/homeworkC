#pragma once

#include <stdint.h>

typedef union {
    double value;
    unsigned char bytes[8];
    uint64_t bits;
} Number;

int getBit(const Number* n, int i);
int theMain();