#include <stdio.h>
#include <string.h>

// https://open.kattis.com/problems/alphabetspam
int main(void) {
    char line[100000];
    scanf("%s", &line);

    int w = 0, l = 0, u = 0, s = 0;
    int str_len = strlen(line);
    for(int i = 0; i < str_len; ++i) {
        // _ = 95
        // a = 97
        // A = 65
        // z = 122
        // Z = 90
        int char_num = (int)line[i];
        if (char_num == 95) {
            ++w;
        } else if(char_num >= 97 && char_num <= 122) {
            ++l;
        } else if(char_num >= 65 && char_num <= 90) {
            ++u;
        } else {
            ++s;
        }
    }
    printf("%.6f\n%.6f\n%.6f\n%.6f", (float)w / (float)str_len, (float)l / (float)str_len, (float)u / (float)str_len, (float)s / (float)str_len);

    return 0;
}