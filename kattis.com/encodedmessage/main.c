#include <stdio.h>
#include <math.h>
#include <string.h>

// https://open.kattis.com/problems/encodedmessage
int main(void) {
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; ++i) {
        char buf[10000];
        scanf("%s", &buf);
        int str_len = strlen(buf);
        int size = (int)sqrt((double)str_len);
        char matrix[size][size];
        int c = 0;
        for (int j = 0; j < size; ++j) {
            for (int k = 0; k < size; ++k) {
                matrix[j][k] = buf[c++];
            }
        }
        for (int j = size - 1; j >= 0; --j) {
            for (int k = 0; k < size; ++k) {
                printf("%c", matrix[k][j]);
            }
        }
        printf("\n");
    }

    return 0;
}