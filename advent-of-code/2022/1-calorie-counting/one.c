#include <stdio.h>
#include <stdlib.h>

// https://adventofcode.com/2022/day/1
int main(void) {
    int calories[255];
    int highestCalories = 0;
    int totalCalories = 0;
    FILE *file = fopen("input.txt", "r");

    char input[255];
    while(fgets(input, sizeof input, file)) {
        if (input[0] == '\n' || input[0] == '\r') {
            // New elf.
            if (totalCalories > highestCalories) {
                highestCalories = totalCalories;
            }
            totalCalories = 0;
        } else {
            totalCalories += atoi(input);
        }
    }

    printf("%d", highestCalories);

    fclose(file);

    return 0;
}