#include <stdio.h>

// 최대공약수(GCD) 계산
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

// 최소공배수(LCM) 계산
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int main() {
    int num1, num2;

    printf("두 숫자를 입력하세요: ");
    scanf("%d %d", &num1, &num2);

    int result_gcd = gcd(num1, num2);
    int result_lcm = lcm(num1, num2);

    printf("최대공약수(GCD): %d\n", result_gcd);
    printf("최소공배수(LCM): %d\n", result_lcm);

    return 0;
}
