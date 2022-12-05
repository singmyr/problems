#include <stdio.h>
#include <string.h>

// https://adventofcode.com/2022/day/5
int main(void) {
    FILE *file = fopen("input.txt", "r");

    char temp_crates[9][255] = {0};
    int temp_counters[9] = {0};
    char crates[9][255] = {0};
    int counters[9] = {0};
    char input[255];
    while(fgets(input, sizeof input, file)) {
        if (input[0] == '\n' || input[0] == '\r') {
            break;
        }
        for (int i = 0; i < strlen(input); ++i) {
            if (input[i] == '[') {
                int position = (int)(i / 4);
                temp_crates[position][temp_counters[position]++] = input[i+1];
            }
        }
    }

    for (int c = 0; c < 9; ++c) {
        for (int i = 254; i >= 0; --i) {
            if (temp_crates[c][i] != '\0') {
                crates[c][counters[c]] = temp_crates[c][i];
                ++counters[c];
            }
        }
    }

    while(fgets(input, sizeof input, file)) {
        if (input[0] != 'm') {
            continue;
        }
        int n = 0, c = 0, t = 0;
        if (sscanf((const char *)&input, "move %d from %d to %d", &n, &c, &t) == 3) {
            --c; // Decrease by 1 to get correct index.
            --t; // Decrease by 1 to get correct index.
            for (int i = 0; i < n; ++i) {
                crates[t][counters[t]] = crates[c][counters[c]-1];
                ++counters[t];

                crates[c][counters[c]-1] = '\0';
                counters[c] -= counters[c] > 0 ? 1 : 0;
            }
        }
    }

    for (int i = 0; i < 9; ++i) {
        if (counters[i] > 0) {
            printf("%c", crates[i][counters[i]-1]);
        }
    }

    fclose(file);

    return 0;
}