#include <stdio.h>
#include <string.h>

// https://adventofcode.com/2022/day/3
int main(void) {
    // a = 97
    // z = 122
    // A = 65
    // Z = 90
    FILE *file = fopen("input.txt", "r");

    char contents[255];
    int i;

    int sum = 0;
    while(fscanf(file, "%s", contents) == 1) {
        int len = (int)strlen(contents);
        char leftCounter[52] = {0};
        char rightCounter[52] = {0};
        char *counter = (char *)&leftCounter;
        for (i = 0; i < len; ++i) {
            if (i >= (int)(len / 2)) {
                counter = (char *)&rightCounter;
            }
            int intval = (int)contents[i];
            int index;
            if (intval <= 90) {
                index = intval - (int)'A' + 26;
            } else {
                index = intval - (int)'a';
            }
            ++counter[index];
        }
        for (i = 0; i < sizeof(leftCounter); ++i) {
            if (leftCounter[i] > 0 && rightCounter[i] > 0) {
                sum += i + 1;
            }
        }
    }

    printf("%d\n", sum);

    fclose(file);

    return 0;
}