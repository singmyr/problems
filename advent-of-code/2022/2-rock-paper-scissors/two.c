#include <stdio.h>

char oRock = 'A';
char oPaper = 'B';
char oScissors = 'C';
char mRock = 'X';
char mPaper = 'Y';
char mScissors = 'Z';
char win = 'Z';
char draw = 'Y';
char lose = 'X';

char getMove(char opponent, char move) {
    if (move == draw) {
        if (opponent == oRock) return mRock;
        if (opponent == oPaper) return mPaper;
        if (opponent == oScissors) return mScissors;
    };
    if (move == win) {
        if (opponent == oRock) return mPaper;
        if (opponent == oPaper) return mScissors;
        if (opponent == oScissors) return mRock;
    }
    if (move == lose) {
        if (opponent == oRock) return mScissors;
        if (opponent == oPaper) return mRock;
        if (opponent == oScissors) return mPaper;
    }

    return ' ';
}

int getMovePoints(char move) {
    int rock = 1;
    int paper = 2;
    int scissors = 3;

    if (move == mRock) return rock;
    if (move == mPaper) return paper;
    if (move == mScissors) return scissors;

    return 0;
}

int getRoundPoints(char opponent, char move) {
    int points = getMovePoints(move);

    int draw = 3;
    int win = 6;

    if (opponent == oRock) {
        if (move == mRock) points += draw;
        if (move == mPaper) points += win;
    }

    if (opponent == oPaper) {
        if (move == mPaper) points += draw;
        if (move == mScissors) points += win;
    }

    if (opponent == oScissors) {
        if (move == mScissors) points += draw;
        if (move == mRock) points += win;
    }

    return points;
}

// https://adventofcode.com/2022/day/2
int main(void) {
    FILE *file = fopen("input.txt", "r");

    char opponent;
    char move;
    int points = 0;
    while(fscanf(file, "%c %c\n", &opponent, &move) == 2) {
        points += getRoundPoints(opponent, getMove(opponent, move));
    }

    printf("%d", points);

    fclose(file);

    return 0;
}