#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// 회문 검사 함수
bool isPalindrome(const char* s, int start, int end) {
    while (start < end) {
        if (s[start] != s[end]) return false;
        start++;
        end--;
    }
    return true;
}

// 문자열의 부분을 출력하는 함수
void printPartition(const char* s, int start, int end) {
    for (int i = start; i <= end; i++) {
        printf("%c", s[i]);
    }
}

// 백트래킹을 통한 분할 출력 함수
void backtrack(const char* s, int start, char* path, int pathIndex) {
    if (start >= strlen(s)) {
        // 경로 출력
        for (int i = 0; i < pathIndex; i++) {
            printf("%s ", path + i * (strlen(s) + 1));
        }
        printf("\n");
        return;
    }

    for (int end = start; end < strlen(s); ++end) {
        if (isPalindrome(s, start, end)) {
            // 현재 부분 문자열을 path에 저장
            for (int i = 0; i <= end - start; i++) {
                path[pathIndex * (strlen(s) + 1) + i] = s[start + i];
            }
            path[pathIndex * (strlen(s) + 1) + (end - start + 1)] = '\0';
            // 다음 부분을 처리
            backtrack(s, end + 1, path, pathIndex + 1);
        }
    }
}

// 메인 함수
int main() {
    const char* s = "aab";
    int length = strlen(s);
    char* path = malloc(length * (length + 1) * sizeof(char)); // 충분한 공간을 할당

    if (path == NULL) {
        perror("Failed to allocate memory");
        return EXIT_FAILURE;
    }

    backtrack(s, 0, path, 0);

    free(path);
    return 0;
}
