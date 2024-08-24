#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "function.h"

bool isPalindrome(const char* s, int start, int end) {
    while (start < end) {
        if (s[start] != s[end]) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

void findLongestPalindrome(const char* s, int* start, int* end) {
    int n = strlen(s);
    int maxLength = 1;  // 최소 팰린드롬 길이는 1

    *start = 0;
    *end = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            // 현재 문자열이 팰린드롬인지 확인
            if (isPalindrome(s, i, j)) {
                int length = j - i + 1;
                if (length > maxLength) {
                    *start = i;
                    *end = j;
                    maxLength = length;
                }
            }
        }
    }
}
