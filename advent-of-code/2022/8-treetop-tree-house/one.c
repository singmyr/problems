#include <stdio.h>
#include <string.h>

#define ATOI(x) ((int)x)-48

// https://adventofcode.com/2022/day/8
int main(void) {
    FILE *file = fopen("input.txt", "r");

    char input[255];
    fscanf(file, "%s", input);
    int cols = strlen(input);
    int grid[255][cols];
    memset(&grid, 0, 255*cols*sizeof(int));
    for (int i = 0; i < strlen(input); ++i) {
        grid[0][i] = ATOI(input[i]);
    }
    int rows = 1;
    while(fscanf(file, "%s", input) == 1) {
        for (int i = 0; i < strlen(input); ++i) {
            grid[rows][i] = ATOI(input[i]);
        }
        ++rows;
    }

    int visible = (rows*2) + (cols*2) - 4;

    for (int y = 1; y < rows - 1; ++y) {
        for (int x = 1; x < cols - 1; ++x) {
            char is_visible = 0;
            // Check up.
            char blocking = 0;
            for (int i = y-1; i >= 0; --i) {
                if (grid[i][x] >= grid[y][x]) ++blocking;
            }
            if (!blocking) is_visible = 1;

            if (!is_visible) {
                // Check down.
                blocking = 0;
                for (int i = y+1; i < rows; ++i) {
                    if (grid[i][x] >= grid[y][x]) ++blocking;
                }
                if (!blocking) is_visible = 1;
            }

            if (!is_visible) {
                // Check left.
                blocking = 0;
                for (int i = x-1; i >= 0; --i) {
                    if (grid[y][i] >= grid[y][x]) ++blocking;
                }
                if (!blocking) is_visible = 1;
            }

            if (!is_visible) {
                // Check right.
                blocking = 0;
                for (int i = x+1; i < cols; ++i) {
                    if (grid[y][i] >= grid[y][x]) ++blocking;
                }
                if (!blocking) is_visible = 1;
            }

            if (is_visible) ++visible;
        }
    }

    printf("%d\n", visible);

    fclose(file);

    return 0;
}