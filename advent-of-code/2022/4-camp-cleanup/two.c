#include <stdio.h>

// https://adventofcode.com/2022/day/4
int main(void) {
    FILE *file = fopen("input.txt", "r");

    int x[2] = {0,0};
    int y[2] = {0,0};
    int pairs = 0;
    while(fscanf(file, "%d-%d,%d-%d", &x[0], &x[1], &y[0], &y[1]) == 4) {
        if (x[0] >= y[0] && x[0] <= y[1]) ++pairs;
        else if (x[1] >= y[0] && x[0] <= y[1]) ++pairs;
        else if (y[0] >= x[0] && y[0] <= x[1]) ++pairs;
        else if (y[1] >= x[0] && y[0] <= x[1]) ++pairs;
    }

    printf("%d\n", pairs);

    fclose(file);

    return 0;
}