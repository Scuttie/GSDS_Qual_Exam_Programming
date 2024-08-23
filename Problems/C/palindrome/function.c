#include <stdbool.h>
#include <string.h>

// 회문인지 확인하는 함수
bool is_palindrome(const char* s) {
    if (s == NULL) {
        return false; // 널 포인터에 대한 예외 처리
    }

    int length = strlen(s);
    
    if (length == 0) {
        return true; // 빈 문자열은 회문으로 간주
    }

    int half_length = length / 2;  // 문자열의 절반 길이 계산 // 소수점 버려짐

    for (int i = 0; i < half_length; i++) {
        if (s[i] != s[length - i - 1]) {
            return false; // 회문이 아니면 false 반환
        }
    }

    return true; // 회문이면 true 반환
}

