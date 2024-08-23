#include <stdio.h>
#include <string.h>  // 문자열 함수들 (strcmp, strlen, strcpy, strcat 등)
#include <strings.h> // strcasecmp, strncasecmp

int main() {
    char str1[100] = "Hello";
    char str2[100] = "hello";
    char str3[100] = "world";
    char dest[100];

    // 문자열 길이 측정 (strlen)
    printf("strlen(str1): %lu\n", strlen(str1));  // 결과: 5

    // 문자열 복사 (strcpy, strncpy)
    strcpy(dest, str1);  // str1을 dest로 복사
    printf("strcpy(dest, str1): %s\n", dest);  // 결과: Hello

    strncpy(dest, str3, 3);  // str3에서 3글자만 복사
    dest[3] = '\0';  // 널 문자로 종료
    printf("strncpy(dest, str3, 3): %s\n", dest);  // 결과: wor

    // 문자열 연결 (strcat, strncat)
    strcpy(dest, str1);  // 먼저 dest에 str1 복사
    strcat(dest, " ");   // 공백 추가
    strcat(dest, str3);  // str3 연결
    printf("strcat(dest, str3): %s\n", dest);  // 결과: Hello world

    strncpy(dest, str1, 3);  // dest에 str1의 3글자 복사
    dest[3] = '\0';  // 널 문자로 종료
    strncat(dest, str3, 2);  // str3에서 2글자 연결
    printf("strncat(dest, str3, 2): %s\n", dest);  // 결과: Helwo

    // 문자열 비교 (strcmp, strncmp, strcasecmp, strncasecmp)
    printf("strcmp(str1, str2): %d\n", strcmp(str1, str2));  // 대소문자 구분 비교, 결과: -32
    printf("strncmp(str1, str2, 3): %d\n", strncmp(str1, str2, 3));  // 앞 3글자 비교, 결과: 0

    printf("strcasecmp(str1, str2): %d\n", strcasecmp(str1, str2));  // 대소문자 구분 안함, 결과: 0
    printf("strncasecmp(str1, str2, 3): %d\n", strncasecmp(str1, str2, 3));  // 앞 3글자 비교, 대소문자 구분 안함, 결과: 0

    // 문자열 검색 (strchr, strrchr, strstr)
    printf("strchr(str1, 'l'): %s\n", strchr(str1, 'l'));  // 'l'을 찾고 나머지 문자열 출력, 결과: llo
    printf("strrchr(str1, 'l'): %s\n", strrchr(str1, 'l'));  // 마지막 'l' 찾기, 결과: lo

    printf("strstr(str1, \"ll\"): %s\n", strstr(str1, "ll"));  // "ll" 찾기, 결과: llo

    // 문자열 토큰화 (strtok)
    char sentence[] = "Hello, World! Welcome to C programming.";
    char *token = strtok(sentence, " ,.!");  // 구분자로 토큰화
    while (token != NULL) {
        printf("Token: %s\n", token);
        token = strtok(NULL, " ,.!");  // 다음 토큰 찾기
    }

    // 메모리 조작 (memcpy, memmove, memcmp, memchr)
    char src[100] = "Memory manipulation";
    memcpy(dest, src, 6);  // src에서 6바이트를 dest로 복사
    dest[6] = '\0';  // 널 문자로 종료
    printf("memcpy(dest, src, 6): %s\n", dest);  // 결과: Memory

    memmove(dest + 1, dest, 5);  // 메모리 겹침 처리
    printf("memmove(dest + 1, dest, 5): %s\n", dest);  // 결과: MMemory

    printf("memcmp(str1, str2, 5): %d\n", memcmp(str1, str2, 5));  // 메모리 비교, 결과: -32

    printf("memchr(str1, 'e', 5): %s\n", memchr(str1, 'e', 5));  // 메모리에서 'e' 찾기, 결과: ello

    // 문자열 숫자 변환 (atoi, atol, atof)
    char num_str[] = "12345";
    printf("atoi(num_str): %d\n", atoi(num_str));  // 결과: 12345

    char float_str[] = "123.45";
    printf("atof(float_str): %.2f\n", atof(float_str));  // 결과: 123.45

    return 0;
}
