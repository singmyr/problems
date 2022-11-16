#include <stdio.h>

// https://open.kattis.com/problems/oddecho
int main(void) {
    int n;
    if (scanf("%d", &n) == 1) {
        char str[100];
        for (int i = 0; i < n; ++i) {
            scanf("%s", &str);
            if (i % 2 == 0) {
                printf("%s\n", str);
            }
        }
    }

    return 0;
}