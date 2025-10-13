#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool reverse(char* str, int size) 
{
    int l = 0;
    int r = size - 1;
    while (l <= r) {
        if (str[l] == str[r]) {
            l++;
            r--;
        } else {
            return false;
        }
    } return true;
}


int main()
{
    char str[11] = "racecar";
    int size = strlen(str);
    reverse(str, size);
    if (reverse(str, size)) {
        printf("Строка является палидромом");
    } else {
        printf("Строка не является палидромом");
    }
    return 0;
}