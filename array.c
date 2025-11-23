#include <stdio.h>

void reverse(int* a, int l, int r)
{
    while (l < r) {
        int t = a[l];
        a[l++] = a[r];
        a[r--] = t;
    }
}

void swap(int* x, int m, int n)
{
    reverse(x, 0, m + n - 1);
    reverse(x, 0, n - 1);
    reverse(x, n, m + n - 1);
}

int main()
{
    int m = 0;
    int n = 0;
    scanf("%d %d", &m, &n);
    int num[m + n];
    for (int i = 0; i < m + n; i++) {
        num[i] = i + 1;
    }

    swap(num, m, n);
    for (int i = 0; i < m + n; i++)
        printf("%d ", num[i]);
    return 0;
}
