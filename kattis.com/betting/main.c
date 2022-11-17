#include <stdio.h>

// https://open.kattis.com/problems/betting
int main(void) {
    int a;
    scanf("%d", &a);
    
    float b1 = (float)a;
    float b2 = 100.0f - b1;

    printf("%.10f\n", (b2 / b1) + 1.0f);
    printf("%.10f\n", (b1 / b2) + 1.0f);

    return 0;
}