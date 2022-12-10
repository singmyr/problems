#include <stdio.h>
#include <stdlib.h>

int x = 1;
int op = 0;
int sum = 0;

void checkSignalStrength() {
    if ((op - 20) % 40 == 0) {
        sum += (op * x);
    }
}

// https://adventofcode.com/2022/day/10
int main(void) {
    FILE *file = fopen("input.txt", "r");

    char input[255];    
    while (fgets(input, sizeof input, file)) {
        if (input[0] == 'a') {
            int n = atoi(&(input[5]));
            for (int i = 0; i < 2; ++i) {
                ++op;
                checkSignalStrength();
            }
            x += n;
        } else {
            ++op;
            checkSignalStrength();
        }
    }

    printf("%d\n", sum);

    fclose(file);

    return 0;
}