#include <stdio.h>

// https://open.kattis.com/problems/cold
int main(void) {
    int n;
    int total = 0;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; ++i) {
            int t;
            if (scanf("%d", &t) == 1) {
                if (t < 0) {
                    ++total;
                }
            }
        }
    }

    printf("%d", total);

    return 0;
}