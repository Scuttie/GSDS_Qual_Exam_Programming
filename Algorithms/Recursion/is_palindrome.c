#include <stdio.h>
#include <string.h>

int is_palindrome(char *s, int start, int end) {
    if (start >= end)
        return 1;
    if (s[start] != s[end])
        return 0;
    return is_palindrome(s, start + 1, end - 1);
}

int main() {
    char str[] = "madam";
    printf("%d\n", is_palindrome(str, 0, strlen(str) - 1));  // Output: 1
    return 0;
}
