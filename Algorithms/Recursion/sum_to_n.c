#include <stdio.h>

int sum_to_n(int n) {
    if (n <= 1)
        return n;
    return n + sum_to_n(n - 1);
}

int main() {
    printf("%d\n", sum_to_n(5));  // Output: 15
    return 0;
}
