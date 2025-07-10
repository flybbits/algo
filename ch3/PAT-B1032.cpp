#include <stdio.h>
#include <algorithm>

int main() {
    int n, id, score, i;
    scanf("%d", &n);
    int scores[n + 1];
    std::fill(scores, scores + n + 1, 0);
    for(i = 1; i <= n; ++i) {
        scanf("%d%d", &id, &score);
        scores[id] += score;
    }
    int max;
    max = 1;
    for(i = 1; i <= n; ++i) {
        if (scores[i] > scores[max]) {
            max = i;
        }
    }
    printf("%d %d\n", max, scores[max]);
    return 0;
}