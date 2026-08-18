#include <stdio.h>

int sum_natural(int n) {
    if (n <= 1) {
        return n;
    }
    return n + sum_natural(n - 1);
}

int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        printf("%d\n", sum_natural(n));
    }
    return 0;
}
