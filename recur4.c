#include <stdio.h>

int sum_digits(long long n) {
    if (n == 0) {
        return 0;
    }
    return (n % 10) + sum_digits(n / 10);
}

int digital_root(long long n) {
    if (n < 10) {
        return n;
    }
    return digital_root(sum_digits(n));
}

int main() {
    long long n;
    if (scanf("%lld", &n) == 1) {
        printf("%d %d\n", sum_digits(n), digital_root(n));
    }
    return 0;
}
