#include <stdio.h>
#include <math.h>

// https://open.kattis.com/problems/sibice
int main(void) {
    int n, w, h, x;
    scanf("%d%d%d", &n, &w, &h);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &x);
        int hyp = (int)sqrtf((float)(w * w + h * h));
        if (x <= w || x <= h || x <= hyp) {
            printf("DA\n");
        } else {
            printf("NE\n");
        }
    }

    return 0;
}