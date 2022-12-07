#include <stdio.h>
#include <string.h>

int sizes[255];
int sizes_iter = 0;

int getDirectorySum(FILE *file) {
    unsigned sum = 0;
    char input[255];
    while (fgets(input, sizeof input, file)) {
        if (input[0] == '$') {
            char command[255], arguments[255];
            sscanf((const char*)input, "$ %s %s", command, arguments);
            if (strcmp((const char*)command, "cd") == 0) {
                if (strcmp((const char*)arguments, "..") == 0) {
                    return sum;
                } else {
                    int directory_sum = getDirectorySum(file);
                    sum += directory_sum;
                    sizes[sizes_iter++] = directory_sum;
                }
            }
        } else if (!(input[0] == 'd' && input[1] == 'i' && input[2] == 'r')) {
            int size = 0;
            char name[255];
            sscanf((const char*)input, "%d %s", &size, name);
            sum += size;
        }
    }
    return sum;
}

// https://adventofcode.com/2022/day/7
int main(void) {
    FILE *file = fopen("input.txt", "r");

    int sum = getDirectorySum(file);
    sizes[sizes_iter++] = sum;

    // quick bubble sort.
    for (int i = 0; i < sizes_iter; ++i) {
        for (int j = 0; j < sizes_iter; ++j) {
            if (sizes[i] < sizes[j]) {
                sizes[i]=sizes[i]^sizes[j];
                sizes[j]=sizes[i]^sizes[j];
                sizes[i]=sizes[i]^sizes[j];
            }
        }
    }

    int goal = sum - 40000000;
    int match = 0;
    for (int i = 0; i < sizes_iter; ++i) {
        if (sizes[i] >= goal) {
            match = sizes[i];
            break;
        }
    }

    printf("%d\n", match);

    fclose(file);

    return 0;
}