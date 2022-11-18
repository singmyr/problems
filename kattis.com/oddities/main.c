#include <stdio.h>

// https://open.kattis.com/problems/oddities
int main(void) {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; ++i) {
            int num;
            if (scanf("%d", &num) == 1) {
                if (num % 2 == 0) {
                    printf("%d is even\n", num);
                } else {
                    printf("%d is odd\n", num);
                }
            }
        }
    }

    return 0;
}