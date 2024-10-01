#include <stdio.h>

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    printf("%d\n", gcd(48, 18));  // Output: 6
    return 0;
}
