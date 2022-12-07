#include <stdio.h>
#include <string.h>

const int MAX_SIZE = 100000;
int allowed_directories_size = 0;

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
                    if (directory_sum <= MAX_SIZE) {
                        allowed_directories_size += directory_sum;
                    }
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
    if (sum <= MAX_SIZE) {
        allowed_directories_size += sum;
    }
    printf("%d\n", allowed_directories_size);

    fclose(file);

    return 0;
}