#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Operation {
    char operand;
    char *left;
    char *right;
} Operation;

typedef struct Monkey {
    struct Operation op;
    int inspect_count;
    int num_items;
    int test;
    int throwIfTrue;
    int throwIfFalse;
    int *items;
} Monkey;

int calculateWorry(int old, struct Operation *op) {
    int parts[2];
    parts[0] = (strcmp(op->left, "old") == 0) ? old : atoi(op->left);
    parts[1] = (strcmp(op->right, "old") == 0) ? old : atoi(op->right);
    int sum = 0;
    switch (op->operand) {
        case '+':
            sum = parts[0] + parts[1];
        break;
        case '*':
            sum = parts[0] * parts[1];
        break;
    }
    return sum;
}

// https://adventofcode.com/2022/day/11
int main(void) {
    FILE *file = fopen("input.txt", "r");

    struct Monkey *monkies = (struct Monkey *)malloc(sizeof(struct Monkey)*8);
    int num_monkies = 0;
    char input[255];
    while (fgets(input, sizeof input, file)) {
        if (input[0] == '\n' || input[0] == '\r') continue;
        int monkey;
        char items[255];
        char operation[255];
        char test[255];
        char if_true[255];
        char if_false[255];
        sscanf(input, "Monkey %d:", &monkey);
        fgets(input, sizeof input, file);
        sscanf(input, "  Starting items: %[^\n]\n", items);
        fgets(input, sizeof input, file);
        sscanf(input, "  Operation: new = %[^\n]\n", operation);
        fgets(input, sizeof input, file);
        sscanf(input, "  Test: divisible by %[^\n]\n", test);
        fgets(input, sizeof input, file);
        sscanf(input, "    If true: throw to monkey %[^\n]\n", if_true);
        fgets(input, sizeof input, file);
        sscanf(input, "    If false: throw to monkey %[^\n]\n", if_false);

        int *real_items = (int *)malloc(sizeof(int)*255);
        int item = 0, n = 0, parse = 1;
        for (int i = 0; i < strlen(items); ++i) {
            if (parse == 1) {
                real_items[n++] = atoi(&items[i]);
                parse = 0;
            }
            if (items[i] == ' ') parse = 1;
        }
        char *left = (char *)malloc(sizeof(char)*5);
        char *right = (char *)malloc(sizeof(char)*5);
        char operand;
        sscanf(operation, "%s %c %s", left, &operand, right);
        struct Operation op = {operand, left, right};
        struct Monkey m = {
            op,
            0,
            n,
            atoi(test),
            atoi(if_true),
            atoi(if_false),
            real_items
        };
        monkies[num_monkies++] = m;
    }

    for (int r = 0; r < 20; ++r) {
        for (int m = 0; m < num_monkies; ++m) {
            struct Monkey *monkey = &monkies[m];
            for (int i = 0; i < monkey->num_items; ++i) {
                int item = monkey->items[i];
                int worry = (int)(calculateWorry(item, &monkey->op) / 3);
                int newMonkeyIndex;
                int newMonkeyItemIndex;
                if (worry % monkey->test == 0) {
                    newMonkeyIndex = monkey->throwIfTrue;
                } else {
                    newMonkeyIndex = monkey->throwIfFalse;
                }
                newMonkeyItemIndex = monkies[newMonkeyIndex].num_items;
                monkies[newMonkeyIndex].items[monkies[newMonkeyIndex].num_items++] = worry;
                monkey->items[i] = 0;
                ++monkey->inspect_count;
            }
            monkey->num_items = 0;
        }
    }

    int highest[2] = {0,0};
    for (int m = 0; m < num_monkies; ++m) {
        if (monkies[m].inspect_count > highest[1]) {
            highest[1] = monkies[m].inspect_count;
        }
        if (monkies[m].inspect_count > highest[0]) {
            highest[1] = highest[0];
            highest[0] = monkies[m].inspect_count;
        }
    }
    printf("%d\n", highest[0] * highest[1]);

    fclose(file);

    return 0;
}