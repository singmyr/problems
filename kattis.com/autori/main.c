#include <stdio.h>
#include <string.h>

// https://open.kattis.com/problems/autori
int main(void) {
    char str[101];
    if (scanf("%s", &str) == 1) {
        char result[101];
        memset(&result, '\0', 101);

        char next_up = 0;
        unsigned short index = 1;
        result[0] = str[0];
        for (int i = 1; i < strlen(str); ++i) {
            if (next_up) {
                result[index++] = str[i];
                next_up = 0;
            } else {
                if (str[i] == '-') {
                    next_up = 1;
                }
            }
        }

        printf("%s", result);
    }

    return 0;
}