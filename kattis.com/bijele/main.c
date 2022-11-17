#include <stdio.h>
#include <string.h>

// https://open.kattis.com/problems/bijele
int main(void) {
    int pieces[6];
    memset(&pieces, 0, 6);
    int a, b, c, d, e, f;
    scanf("%d%d%d%d%d%d", &pieces[0], &pieces[1], &pieces[2], &pieces[3], &pieces[4], &pieces[5]);

    int wanted[] = {1, 1, 2, 2, 2, 8};

    for (int i = 0; i < 6; ++i) {
        printf("%d ", wanted[i] - pieces[i]);
    }

    return 0;
}