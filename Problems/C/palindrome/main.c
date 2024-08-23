#include <stdio.h>
#include <stdbool.h>
#include "function.h" // function.c의 함수 원형을 포함
//gcc -o palindrome_test main.c function.c

int main() {
    // 테스트 케이스 설정
    const char* test_cases[][2] = {
        {"racecar", "True"},
        {"hello", "False"},
        {"level", "True"},
        {"noon", "True"},
        {"palindrome", "False"},
    };

    int num_tests = sizeof(test_cases) / sizeof(test_cases[0]);

    // 테스트 케이스 실행 및 결과 확인
    for (int i = 0; i < num_tests; i++) {
        const char* input = test_cases[i][0];
        const char* expected_str = test_cases[i][1];
        bool expected = (strcmp(expected_str, "True") == 0);
        bool result = is_palindrome(input);

        printf("Test case %d: Input: '%s' | Expected: %s | Result: %s\n", i + 1, input, expected_str, result ? "True" : "False");
        if (result != expected) {
            printf("Test case %d failed!\n", i + 1);
            return 1; // 실패 시 프로그램 종료
        }
    }

    printf("All test cases passed!\n");
    return 0;
}
