#include <stdio.h>
#include <string.h>
#include "function.h"
#include <stdbool.h>

int main() {
    // 테스트 케이스 설정
    const char* test_cases[] = {
        "abacde",   // Example 1
        "abdeda",   // Example 2
        "a",        // Example 3
        "abcba",    // Example 4
        "noon",     // Example 5
        "racecar",  // Example 6
        "abcdecba"  // Example 7
    };

    int num_tests = sizeof(test_cases) / sizeof(test_cases[0]);

    // 테스트 케이스 실행 및 결과 확인
    for (int i = 0; i < num_tests; i++) {
        const char* input = test_cases[i];
        int start = 0, end = 0;

        findLongestPalindrome(input, &start, &end);

        printf("Test case %d:\n", i + 1);
        printf("  Input: '%s'\n", input);
        printf("  Palindromic Substring is from index %d to %d: '%.*s'\n",
               start, end, end - start + 1, input + start);
        printf("\n");
    }

    return 0;
}
