#include <stdio.h>
#include <string.h>

void reverse_string(char* str) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

int main() {
    char input[101];  // 문자열 길이는 최대 100자 + null terminator
    printf("문자열을 입력하세요: ");
    fgets(input, 101, stdin);
    
    // fgets는 마지막에 개행 문자를 포함하므로 이를 제거합니다.
    input[strcspn(input, "\n")] = 0;
    
    reverse_string(input);
    
    printf("반전된 문자열: %s\n", input);
    
    return 0;
}
