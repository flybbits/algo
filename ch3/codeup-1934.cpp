#include <stdio.h>
#include <algorithm>


int BinarySearch(int arr[], int l, int r, int x) {
    int mid;
    while (l <= r) {
        mid = l + ((r - l) >> 1);
        if (arr[mid] == x) return mid;
        else if (arr[mid] < x) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}


int main() {
    int i, n, x;
    scanf("%d", &n);
    int arr[n];
    for(i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    std::sort(arr, arr + n - 1);
    scanf("%d", &x);
    printf("%d %d", BinarySearch(arr, 0, n-1, 6), BinarySearch(arr, 0, n-1, 10));

    return 0;
}