#include <stdio.h>
#include <stdlib.h>

const int GRID_SIZE = 10000;
int grid[GRID_SIZE][GRID_SIZE] = {0};
int h_pos_x = (int)GRID_SIZE/2;
int h_pos_y = (int)GRID_SIZE/2;
int t_pos_x = (int)GRID_SIZE/2;
int t_pos_y = (int)GRID_SIZE/2;

// https://adventofcode.com/2022/day/9
int main(void) {
    FILE *file = fopen("input.txt", "r");

    char direction;
    int steps = 0;
    
    char input[255];
    while(fscanf(file, "%c %d\n", &direction, &steps) == 2) {
        for (int i = 0; i < steps; ++i) {
            switch (direction) {
                case 'U':
                    --h_pos_y;
                break;
                case 'D':
                    ++h_pos_y;
                break;
                case 'L':
                    --h_pos_x;
                break;
                case 'R':
                    ++h_pos_x;
                break;
            }
            // Calculate head/tail diff and move tail.
            if (h_pos_x == t_pos_x) {
                if (abs(h_pos_y - t_pos_y) >= 2) {
                    t_pos_y += (h_pos_y > t_pos_y) ? 1 : -1;
                }
            } else if (h_pos_y == t_pos_y) {
                if (abs(h_pos_x - t_pos_x) >= 2) {
                    t_pos_x += (h_pos_x > t_pos_x) ? 1 : -1;
                }
            } else if (abs(h_pos_x - t_pos_x) > 1 || abs(h_pos_y - t_pos_y) > 1) {
                // It's too far away, move diagonally.
                if (h_pos_x > t_pos_x) {
                    ++t_pos_x;
                } else {
                    --t_pos_x;
                }
                if (h_pos_y > t_pos_y) {
                    ++t_pos_y;
                } else {
                    --t_pos_y;
                }
            }
            ++grid[t_pos_y][t_pos_x];
        }
    }

    // Calculate how many points have been touched by the tail.
    int sum = 0;
    for (int y = 0; y < GRID_SIZE; ++y) {
        for (int x = 0; x < GRID_SIZE; ++x) {
            if (grid[y][x] > 0) {
                ++sum;
            }
        }
    }

    printf("%d\n", sum);

    fclose(file);

    return 0;
}