#ifndef FUNCTION_H
#define FUNCTION_H
#include <stdbool.h>

bool isPalindrome(const char* s, int start, int end);
void findLongestPalindromeHelper(const char* s, int left, int right, int* result_start, int* result_end);
void findLongestPalindrome(const char* s, int* start, int* end);

#endif
