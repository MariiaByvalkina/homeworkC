#include <stdio.h>

int collect[33];

int fib(int a) 
{
    if (a == 0) {
        collect[0] = 0;
        return collect[0];
    }
    if (a == 1) {
        collect[1] = 1;
        return collect[1];
    } else {
        collect[a] = collect[a - 1] + collect[a - 2];
        return collect[a];
    }

}

int sum(int a)
{   
    int sum = 0;
    fib(a);
    for (int i = 0; i < a; i++) {
        fib(i);
        if (collect[i] % 2 == 0) {
            sum+=collect[i];
        }
    }
    return sum;
}

int main() 
{
    int n = 33;
    for (int i = 0; i < n; i++) {
        fib(i);
        printf("%d ", collect[i]);
    }
    printf("\n");
    int sum1 = sum(n);
    printf("%d", sum1);
    return 0;
}