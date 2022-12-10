#include <stdio.h>
#include <stdlib.h>

int x = 1;
int op = 0;
int pos = 0;

void draw() {
    if (abs(pos - x) <= 1) {
        printf("#");
    } else {
        printf(".");
    }
    ++pos;
    if (pos == 40) {
        printf("\n");
        pos = 0;
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
                draw();
            }
            x += n;
        } else {
            ++op;
            draw();
        }
    }

    fclose(file);

    return 0;
}