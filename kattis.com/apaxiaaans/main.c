#include <stdio.h>
#include <string.h>

// https://open.kattis.com/problems/apaxiaaans
int main(void) {
    char line[250];
    char result[250];
    scanf("%s", &line);

    int str_len = strlen(line);
    int next_pos = 0;
    char previous = line[0];
    result[next_pos++] = previous;
    for(int i = 1; i < str_len; ++i) {
        if (line[i] != previous) {
            result[next_pos++] = line[i];
            previous = line[i];
        }
    }
    result[next_pos] = '\0';

    printf("%s", result);

    return 0;
}