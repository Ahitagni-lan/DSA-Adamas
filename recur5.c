#include <stdio.h>
#include <ctype.h>
#include <string.h>

int is_palindrome_rec(const char *str, int left, int right) {
    if (left >= right) {
        return 1;
    }
    if (!isalpha((unsigned char)str[left])) {
        return is_palindrome_rec(str, left + 1, right);
    }
    if (!isalpha((unsigned char)str[right])) {
        return is_palindrome_rec(str, left, right - 1);
    }
    if (tolower((unsigned char)str[left]) != tolower((unsigned char)str[right])) {
        return 0;
    }
    return is_palindrome_rec(str, left + 1, right - 1);
}

int main() {
    char str[205];
    if (fgets(str, sizeof(str), stdin) != NULL) {
        int len = strlen(str);
        if (len > 0 && str[len - 1] == '\n') {
            str[len - 1] = '\0';
            len--;
        }
        if (is_palindrome_rec(str, 0, len - 1)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}
