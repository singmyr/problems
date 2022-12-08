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

    int highest_score = 0;
    for (int y = 0; y < rows; ++y) {
        for (int x = 0; x < cols; ++x) {
            int score = 0;
            // Check up.
            int trees = 0;
            for (int i = y-1; i >= 0; --i) {
                ++trees;
                if (grid[i][x] >= grid[y][x]) break;
            }
            score = trees;

            // Check down.
            trees = 0;
            for (int i = y+1; i < rows; ++i) {
                ++trees;
                if (grid[i][x] >= grid[y][x]) break;
            }
            score *= trees;

            // Check left.
            trees = 0;
            for (int i = x-1; i >= 0; --i) {
                ++trees;
                if (grid[y][i] >= grid[y][x]) break;
            }
            score *= trees;

            // Check right.
            trees = 0;
            for (int i = x+1; i < cols; ++i) {
                ++trees;
                if (grid[y][i] >= grid[y][x]) break;
            }
            score *= trees;

            if (score > highest_score) {
                highest_score = score;
            }
        }
    }

    printf("%d\n", highest_score);

    fclose(file);

    return 0;
}