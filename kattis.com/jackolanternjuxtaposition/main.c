#include <stdio.h>

// https://open.kattis.com/problems/jackolanternjuxtaposition
int main(void) {
    int a, b, c;
    if (scanf("%d %d %d", &a, &b, &c) == 3) {
        printf("%d", a * b * c);
    }

    return 0;
}