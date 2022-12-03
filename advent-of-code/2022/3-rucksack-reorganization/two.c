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
    int currentElf = 0;
    char counters[3][52] = {{0}, {0}, {0}};
    while(fscanf(file, "%s", contents) == 1) {
        int len = (int)strlen(contents);
        char *counter = (char *)&counters[currentElf++];
        for (i = 0; i < len; ++i) {
            int intval = (int)contents[i];
            int index;
            if (intval <= 90) {
                index = intval - (int)'A' + 26;
            } else {
                index = intval - (int)'a';
            }
            ++counter[index];
        }
        if (currentElf > 2) {
            for (i = 0; i < sizeof(counters[0]); ++i) {
                if (counters[0][i] > 0 && counters[1][i] > 0 && counters[2][i] > 0) {
                    sum += i + 1;
                }
            }
            currentElf = 0;
            memset(&counters[0], 0, sizeof(counters[0]));
            memset(&counters[1], 0, sizeof(counters[1]));
            memset(&counters[2], 0, sizeof(counters[2]));
        }
    }

    printf("%d\n", sum);

    fclose(file);

    return 0;
}