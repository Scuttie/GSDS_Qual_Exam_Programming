#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

bool isPalindrome(char* s) {
    /*
    주어진 문자열이 회문인지 여부를 판단합니다.
    알파벳과 숫자만을 고려하며, 대소문자를 무시합니다.
    
    매개변수:
    s (char*): 평가할 입력 문자열
    
    반환값:
    bool: 회문이면 true, 아니면 false
    */
    
    // 왼쪽 포인터와 오른쪽 포인터를 문자열의 양 끝으로 초기화
    int left = 0;
    int right = strlen(s) - 1;
    
    while (left < right) {
        // 왼쪽 포인터가 가리키는 문자가 알파벳이나 숫자가 아니면 오른쪽으로 이동
        while (left < right && !isalnum(s[left])) {
            left++;
        }
        
        // 오른쪽 포인터가 가리키는 문자가 알파벳이나 숫자가 아니면 왼쪽으로 이동
        while (left < right && !isalnum(s[right])) {
            right--;
        }
        
        // 현재 왼쪽과 오른쪽 포인터가 가리키는 문자를 소문자로 변환하여 비교
        if (tolower(s[left]) != tolower(s[right])) {
            // 문자가 다르면 회문이 아니므로 false 반환
            return false;
        }
        
        // 양쪽 포인터를 중앙으로 이동
        left++;
        right--;
    }
    
    // 모든 문자가 일치하면 회문이므로 true 반환
    return true;
}

// 예제 테스트를 위한 메인 함수
int main() {
    // 예제 1
    char s1[] = "A man, a plan, a canal: Panama";
    if (isPalindrome(s1)) {
        printf("예제 1: True\n"); // 출력: True
    } else {
        printf("예제 1: False\n");
    }
    
    // 예제 2
    char s2[] = "race a car";
    if (isPalindrome(s2)) {
        printf("예제 2: True\n"); // 출력: False
    } else {
        printf("예제 2: False\n");
    }
    
    // 예제 3
    char s3[] = " ";
    if (isPalindrome(s3)) {
        printf("예제 3: True\n"); // 출력: True
    } else {
        printf("예제 3: False\n");
    }
    
    return 0;
}
