#include <stdio.h>

// https://open.kattis.com/problems/echoechoecho
int main(void) {
    char str[15];
    if (scanf("%s", &str) == 1) {
        printf("%s %s %s", str, str, str);
    }

    return 0;
}