#include <stdio.h>

void hanoi(int n, char source, char target, char auxiliary) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, target);
        return;
    }
    hanoi(n - 1, source, auxiliary, target);
    printf("Move disk %d from %c to %c\n", n, source, target);
    hanoi(n - 1, auxiliary, target, source);
}

int main() {
    hanoi(3, 'A', 'C', 'B');
    return 0;
}
