#include <stdio.h>

// https://open.kattis.com/problems/ninetynine
int main(void) {
    int num = 1;
    do {
        if (num > 1) {
            if (num == 98) {
                num += 1;
            } else {
                num += 3 - (num % 3);
            }
        }
        printf("%d\n", num);
        fflush(stdout);
        if (num == 99) {
            break;
        }

        if (scanf("%d", &num) == 1) {
            if (num == 99) {
                break;
            }
        }
    } while (num < 99);

    return 0;
} 