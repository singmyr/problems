#include <stdio.h>
#include <stdlib.h>

const int GRID_SIZE = 10000;
int grid[GRID_SIZE][GRID_SIZE] = {0};
int knots_pos[10][2] = {0};
int HEAD = 0;
int TAIL = 9;

// https://adventofcode.com/2022/day/9
int main(void) {
    FILE *file = fopen("input.txt", "r");

    char direction;
    int steps = 0;
    
    for (int i = 0; i < 10; ++i) {
        knots_pos[i][0] = (int)GRID_SIZE/2;
        knots_pos[i][1] = (int)GRID_SIZE/2;
    }
    while(fscanf(file, "%c %d\n", &direction, &steps) == 2) {
        for (int i = 0; i < steps; ++i) {
            switch (direction) {
                case 'U':
                    --knots_pos[HEAD][1];
                break;
                case 'D':
                    ++knots_pos[HEAD][1];
                break;
                case 'L':
                    --knots_pos[HEAD][0];
                break;
                case 'R':
                    ++knots_pos[HEAD][0];
                break;
            }
            for (int k = 1; k <= TAIL; ++k) {
                int p_pos_x = knots_pos[k-1][0];
                int p_pos_y = knots_pos[k-1][1];
                int c_pos_x = knots_pos[k][0];
                int c_pos_y = knots_pos[k][1];
                if (p_pos_x == c_pos_x) {
                    if (abs(p_pos_y - c_pos_y) >= 2) {
                        knots_pos[k][1] += (p_pos_y > c_pos_y) ? 1 : -1;
                    }
                } else if (p_pos_y == c_pos_y) {
                    if (abs(p_pos_x - c_pos_x) >= 2) {
                        knots_pos[k][0] += (p_pos_x > c_pos_x) ? 1 : -1;
                    }
                } else if (abs(p_pos_x - c_pos_x) > 1 || abs(p_pos_y - c_pos_y) > 1) {
                    if (p_pos_x > c_pos_x) {
                        ++knots_pos[k][0];
                    } else {
                        --knots_pos[k][0];
                    }
                    if (p_pos_y > c_pos_y) {
                        ++knots_pos[k][1];
                    } else {
                        --knots_pos[k][1];
                    }
                }
            }
            ++grid[knots_pos[TAIL][1]][knots_pos[TAIL][0]];
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