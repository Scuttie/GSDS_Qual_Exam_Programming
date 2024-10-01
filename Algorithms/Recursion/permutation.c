#include <stdio.h>

void swap(char *x, char *y) {
    char temp = *x;
    *x = *y;
    *y = temp;
}

void permute(char *s, int l, int r) {
    if (l == r) {
        printf("%s\n", s);
    } else {
        for (int i = l; i <= r; i++) {
            swap((s + l), (s + i));  // Swap
            permute(s, l + 1, r);
            swap((s + l), (s + i));  // Backtrack
        }
    }
}

int main() {
    char str[] = "ABC";
    int n = 3;
    permute(str, 0, n - 1);
    return 0;
}
