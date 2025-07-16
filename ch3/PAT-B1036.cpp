#include <cstdio>
#include <cstdlib>

int main() {
    int col, row, i, j;
    char C;
    scanf("%d %c", &col, &C);
    row = col % 2 == 0 ? col / 2 : col / 2 + 1;
    for(i = 0; i < row; ++i) {
        if(i == 0 || i == row - 1) {
            for(j = 0; j < col; ++j) {
                printf("%c", C);
            }
        }
        else {
            printf("%c", C);
            for(j = 1; j < col-1; ++j) {
                printf(" ");
            }
            printf("%c", C);
        }
        printf("\n");
    }

    return 0;
} 