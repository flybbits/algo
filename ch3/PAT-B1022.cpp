#include <cstdio>

char bits[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

int b2d(int base, int num) {
    int out = 0;
    while(num != 0) {
        out += ((num % 10) * base);
        num /= 10;
        base *= base;
    }
    return out;
}

int d2b(int base, int num) {
    int weights = 1, out = 0;
    while(num != 0) {
        out += ((num % base) * weights);
        weights *= 10;
        num /= base;
    }
    return out;
}

int main() {
    int a, b, d;
    scanf("%d%d%d", &a, &b, &d);
    a += b;
    printf("%d", d2b(d, a));
    return 0;
}