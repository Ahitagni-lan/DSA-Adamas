#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return (*(char *)a - *(char *)b);
}

void swap(char *x, char *y) {
    char temp = *x;
    *x = *y;
    *y = temp;
}

int should_swap(char str[], int start, int curr) {
    for (int i = start; i < curr; i++) {
        if (str[i] == str[curr]) {
            return 0;
        }
    }
    return 1;
}

void permute(char str[], int index, int len, int *count) {
    if (index == len) {
        printf("%s\n", str);
        (*count)++;
        return;
    }
    for (int i = index; i < len; i++) {
        if (should_swap(str, index, i)) {
            swap(&str[index], &str[i]);
            permute(str, index + 1, len, count);
            swap(&str[index], &str[i]);
        }
    }
}

int main() {
    char str[10];
    if (scanf("%s", str) == 1) {
        int len = strlen(str);
        qsort(str, len, sizeof(char), cmp);
        int count = 0;
        permute(str, 0, len, &count);
        printf("Total = %d\n", count);
    }
    return 0;
}
