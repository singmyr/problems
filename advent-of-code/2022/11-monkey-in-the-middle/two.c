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
    unsigned long long int inspect_count;
    int num_items;
    int throwIfTrue;
    int throwIfFalse;
    unsigned long long int test;
    unsigned long long int *items;
} Monkey;

// https://adventofcode.com/2022/day/11
int main(void) {
    FILE *file = fopen("input.txt", "r");

    struct Monkey *monkies = (struct Monkey *)malloc(sizeof(struct Monkey)*8);
    int num_monkies = 0;
    char input[255];
    const int MONKIES = 8;
    int divisors[MONKIES];
    while (fgets(input, sizeof input, file)) {
        if (input[0] == '\n' || input[0] == '\r') continue;
        int monkey;
        char items[255], operation[255], test[255], if_true[255], if_false[255];
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

        unsigned long long int *real_items = (unsigned long long int *)malloc(sizeof(unsigned long long int)*255);
        int item = 0, n = 0, parse = 1;
        for (int i = 0; i < strlen(items); ++i) {
            if (parse == 1) {
                real_items[n++] = (unsigned long int)atoi(&items[i]);
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
            atoi(if_true),
            atoi(if_false),
            (unsigned long long int)atoi(test),
            real_items
        };
        divisors[num_monkies] = (unsigned long long int)atoi(test);
        monkies[num_monkies++] = m;
    }
    int common = 1;
    for (int i = 0; i < MONKIES; ++i) common *= divisors[i];

    for (int r = 0; r < 10000; ++r) {
        for (int m = 0; m < num_monkies; ++m) {
            struct Monkey *monkey = &monkies[m];
            for (int i = 0; i < monkey->num_items; ++i) {
                unsigned long long int parts[2];
                if (strcmp(monkey->op.left, "old") == 0) {
                    parts[0] = monkey->items[i];
                } else {
                    parts[0] = (unsigned long long int)atoi(monkey->op.left);
                }
                if (strcmp(monkey->op.right, "old") == 0) {
                    parts[1] = monkey->items[i];
                } else {
                    parts[1] = (unsigned long long int)atoi(monkey->op.right);
                }
                unsigned long long int worry = 0;
                switch (monkey->op.operand) {
                    case '+':
                        worry = parts[0] + parts[1];
                    break;
                    case '*':
                        worry = parts[0] * parts[1];
                    break;
                }
                int newMonkeyIndex;
                if (worry % monkey->test == 0) {
                    newMonkeyIndex = monkey->throwIfTrue;
                } else {
                    newMonkeyIndex = monkey->throwIfFalse;
                }
                worry = worry % common;
                monkies[newMonkeyIndex].items[monkies[newMonkeyIndex].num_items++] = worry;
                monkey->items[i] = 0;
                ++monkey->inspect_count;
            }
            monkey->num_items = 0;
        }
    }

    unsigned long long int highest[2] = {0,0};
    for (int m = 0; m < num_monkies; ++m) {
        if (monkies[m].inspect_count > highest[1]) {
            highest[1] = monkies[m].inspect_count;
        }
        if (monkies[m].inspect_count > highest[0]) {
            highest[1] = highest[0];
            highest[0] = monkies[m].inspect_count;
        }
    }

    printf("%llu\n", highest[0] * highest[1]);

    fclose(file);

    return 0;
}