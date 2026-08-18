#include <stdio.h>

int binary_search_rec(int arr[], int left, int right, int key) {
    if (left > right) {
        return -1;
    }
    int mid = left + (right - left) / 2;
    if (arr[mid] == key) {
        return mid;
    }
    if (arr[mid] > key) {
        return binary_search_rec(arr, left, mid - 1, key);
    }
    return binary_search_rec(arr, mid + 1, right, key);
}

int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        int arr[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        int key;
        scanf("%d", &key);
        printf("%d\n", binary_search_rec(arr, 0, n - 1, key));
    }
    return 0;
}
