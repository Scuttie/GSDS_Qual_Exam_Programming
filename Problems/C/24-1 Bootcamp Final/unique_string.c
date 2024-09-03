#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LEN 1000

void uniqueCharacters(const char *filename) {
    /*Write your code here*/
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file\n");
        return;
    }
    
    bool seen[256] = {false};  // ASCII 문자를 기준으로 배열 초기화
    char output[MAX_LEN] = ""; // 결과를 저장할 문자열
    int index = 0;
    char c;
    
    while ((c = fgetc(file)) != EOF) {
        if (c != ' ' && !seen[(unsigned char)c]) {  // 공백을 제외하고, 처음 보는 문자인 경우
            output[index++] = c;  // output 배열에 문자 추가
            seen[(unsigned char)c] = true;  // 해당 문자를 기록
        }
    }

    output[index] = '\0';  // 문자열 끝에 NULL 문자 추가

    /////////////////////
    printf("%s", output);
    fclose(file);
}

int main(int argc, char *argv[]) {
    uniqueCharacters(argv[1]);
    return 0;
}
