#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return abs(a * b) / gcd(a, b);
}

int main() {
    printf("GCD: %d\n", gcd(48, 18));  // Output: 6
    printf("LCM: %d\n", lcm(12, 18));  // Output: 36
    return 0;
}
