#include <stdio.h>
#include <stdlib.h>

// https://adventofcode.com/2022/day/1
int main(void) {
    int calories[255];
    int highestCalories[3] = {0,0,0};
    int totalCalories = 0;
    FILE *file = fopen("input.txt", "r");

    char input[255];
    int i = 0;
    while(fgets(input, sizeof input, file)) {
        if (input[0] == '\n' || input[0] == '\r') {
            // New elf.

            // Don't like doing it this way but whatever, it works.
            if (totalCalories > highestCalories[0]) {
                highestCalories[2] = highestCalories[1];
                highestCalories[1] = highestCalories[0];
                highestCalories[0] = totalCalories;
            } else if (totalCalories > highestCalories[1]) {
                highestCalories[2] = highestCalories[1];
                highestCalories[1] = totalCalories;
            } else if (totalCalories > highestCalories[2]) {
                highestCalories[2] = totalCalories;
            }
            totalCalories = 0;
        } else {
            totalCalories += atoi(input);
        }
    }

    printf("%d", highestCalories[0]+highestCalories[1]+highestCalories[2]);

    fclose(file);

    return 0;
}