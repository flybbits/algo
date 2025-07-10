#include <stdio.h>

int premise(int n) {
    int steps;
    steps = 0;
    while(n != 1) {
        if (n % 2 == 0) {
            n /= 2;
        } else {
            n = (3 * n + 1) / 2;
        }
        steps++;
    }
    printf("%d: %d\n", n, steps);
    return 0;
}


int main() {
    int i;
    for(i = 1; i < 1000; ++i) {
        premise(i);
    }
    return 0;
}