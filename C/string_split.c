#include <stdio.h>
#include <string.h>

void split(const char* str, char delimiter) {
    char* str_copy = strdup(str);  // 원본 문자열을 손상시키지 않기 위해 복사본을 만듭니다.
    char* token = strtok(str_copy, &delimiter);
    
    while (token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, &delimiter);
    }
    
    free(str_copy);  // strdup로 할당된 메모리를 해제합니다.
}

int main() {
    const char* text = "one:two:three:four";
    split(text, ':');
    
    return 0;
}
