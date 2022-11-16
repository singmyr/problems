#include <stdio.h>

// https://open.kattis.com/problems/r2
int main(void) {
    long long r1, s;
    if (scanf("%lld%lld", &r1, &s) == 2) {
        printf("%lld", (s*2)-r1);
    }

    return 0;
}