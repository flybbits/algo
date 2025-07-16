#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const int MAXN = 85;

int main() {
    char str[MAXN];
    char ans[MAXN][MAXN];
    fgets(str, MAXN, stdin);
    int len = strlen(str) - 1, i = 0, j = 0, k;
    for(k = 0; k < len; ++k) {
        if(str[k] != ' ') {
            ans[i][j++] = str[k];
        } else {
            ans[i][j] = '\0';
            i++;
            j = 0;
        }
    }
    for(k = i; k >= 0; --k) {
        printf("%s", ans[k]);
        if(i != 0) printf(" ");
    }
}