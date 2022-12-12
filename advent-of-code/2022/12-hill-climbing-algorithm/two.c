#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char grid[255][255] = {0};
unsigned int counter[255][255];
int WIDTH = 0, HEIGHT = 0;
int start[2] = {0,0}, end[2] = {0,0};

void crawl(int x, int y) {
    int cur = (int)grid[y][x];
    int sum = counter[y][x] + 1;
    if (x > 0) {
        if ((int)grid[y][x-1] - cur >= -1 && (counter[y][x-1] == -1 || counter[y][x-1] > sum)) {
            counter[y][x-1] = counter[y][x] + 1;
            crawl(x-1, y);
        }
    }
    if (x < WIDTH) {
        if ((int)grid[y][x+1] - cur >= -1 && (counter[y][x+1] == -1 || counter[y][x+1] > sum)) {
            counter[y][x+1] = counter[y][x] + 1;
            crawl(x+1, y);
        }
    }
    if (y > 0) {
        if ((int)grid[y-1][x] - cur >= -1 && (counter[y-1][x] == -1 || counter[y-1][x] > sum)) {
            counter[y-1][x] = counter[y][x] + 1;
            crawl(x, y-1);
        }
    }
    if (y < HEIGHT) {
        if ((int)grid[y+1][x] - cur >= -1 && (counter[y+1][x] == -1 || counter[y+1][x] > sum)) {
            counter[y+1][x] = counter[y][x] + 1;
            crawl(x, y+1);
        }
    }
}

// https://adventofcode.com/2022/day/12
int main(void) {
    FILE *file = fopen("input.txt", "r");

    char input[255];
    unsigned char start_found = 0, end_found = 0;
    while (fscanf(file, "%s", input) == 1) {
        WIDTH = strlen(input);
        for (int i = 0; (start_found == 0 || end_found == 0) &&i < strlen(input); ++i) {
            if (input[i] == 'S') {
                start_found = 1;
                start[0] = i;
                start[1] = HEIGHT;
                input[i] = 'a';
            }
            if (input[i] == 'E') {
                end[0] = i;
                end[1] = HEIGHT;
                end_found = 1;
                input[i] = 'z';
            }
        }
        strcpy(grid[HEIGHT++], (const char *)input);
    }
    memset(counter, -1, 255*255);
    counter[end[1]][end[0]] = 0;
    crawl(end[0], end[1]);

    int lowest = -1;
    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            if (grid[y][x] == 'a') {
                int n = counter[y][x];
                if (n > -1 && (lowest == -1 || n < lowest)) lowest = n;
            }
        }
    }
    printf("%d\n", lowest);

    fclose(file);

    return 0;
}