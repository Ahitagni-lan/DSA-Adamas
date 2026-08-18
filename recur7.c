#include <stdio.h>

void hanoi(int n, char source, char aux, char dest, int *moves) {
    if (n == 1) {
        printf("Move disc 1 from %c to %c\n", source, dest);
        (*moves)++;
        return;
    }
    hanoi(n - 1, source, dest, aux, moves);
    printf("Move disc %d from %c to %c\n", n, source, dest);
    (*moves)++;
    hanoi(n - 1, aux, source, dest, moves);
}

int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        int moves = 0;
        hanoi(n, 'A', 'B', 'C', &moves);
        printf("Total moves = %d\n", moves);
    }
    return 0;
}
