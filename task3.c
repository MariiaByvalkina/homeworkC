#include <stdio.h>

int main() {
    int kc = 0;
    for (int s = 0; s < 28; s++) {
        int k = 0;
        for (int a = 0; a < 10; a++) {
            for (int b = 0; b < 10; b++) {
                for (int c = 0; c < 10; c++) {
                    if (a + b + c == s) {
                        k++;
                    }
                }
            }
        }
        kc += k*k;
    }
    printf("%d", kc);
    return 0;
}
