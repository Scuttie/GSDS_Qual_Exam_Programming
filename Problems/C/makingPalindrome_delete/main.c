#include <stdio.h>
#include <string.h>
#include "function.h"

int main() {
    // 테스트 케이스 설정
    const char* test_cases[] = {
        "atcyducia",    // Example 1
        "abcdba",       // Example 2
        "race",         // Example 3
        "abca",         // Example 4
        "abcda",        // Example 5
        "madam",        // Example 6
        "a",            // Example 7
        "ab",           // Example 8
        "abcde",        // Example 9
        "noon"          // Example 10
    };

    const char* expected_results[] = {
        "acdca",        // Expected Palindrome for Example 1
        "abcba",        // Expected Palindrome for Example 2
        "ace",          // Expected Palindrome for Example 3 (only removal, no addition)
        "aca",          // Expected Palindrome for Example 4
        "aca",          // Expected Palindrome for Example 5
        "madam",        // Expected Palindrome for Example 6
        "a",            // Expected Palindrome for Example 7
        "a",            // Expected Palindrome for Example 8
        "a",            // Expected Palindrome for Example 9
        "noon"          // Expected Palindrome for Example 10
    };

    int expected_removal_counts[] = {
        4, 1, 2, 1, 2, 0, 0, 1, 4, 0
    };

    int num_tests = sizeof(test_cases) / sizeof(test_cases[0]);

    // 테스트 케이스 실행 및 결과 확인
    for (int i = 0; i < num_tests; i++) {
        char result[100]; // 만들어진 회문을 저장할 배열
        int removal_count = makingPalindrome(test_cases[i], result);

        printf("Test case %d:\n", i + 1);
        printf("  Input: '%s'\n", test_cases[i]);
        printf("  Expected Palindrome: '%s'\n", expected_results[i]);
        printf("  Expected Removals: %d\n", expected_removal_counts[i]);
        printf("  Result Palindrome: '%s'\n", result);
        printf("  Removals: %d\n", removal_count);

        // 정답과 비교
        if (strcmp(result, expected_results[i]) == 0 && removal_count == expected_removal_counts[i]) {
            printf("  Test case %d passed!\n", i + 1);
        } else {
            printf("  Test case %d failed!\n", i + 1);
        }
        printf("\n");
    }

    return 0;
}
