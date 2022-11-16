#include <stdio.h>

// https://open.kattis.com/problems/99problems
int main(void) {
    int n;
    if (scanf("%d", &n) == 1) {
        // Only edge case.
        if (n < 99) {
            printf("%d", 99);
        } else {
            int rem = n % 100;
            if (rem < 49) {
                printf("%d", n - rem - 1);
            } else {
                printf("%d", n + (99 - rem));
            }
        }
    }

    return 0;
}