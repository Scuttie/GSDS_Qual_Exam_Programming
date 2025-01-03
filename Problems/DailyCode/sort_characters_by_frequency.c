#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 문자와 그 빈도수를 저장하기 위한 구조체 정의
typedef struct {
    char character;  // 문자
    int frequency;   // 문자의 빈도수
} CharFreq;

// qsort를 위한 비교 함수: 빈도수를 기준으로 내림차순 정렬
int compare(const void *a, const void *b) {
    CharFreq *cf1 = (CharFreq *)a;
    CharFreq *cf2 = (CharFreq *)b;
    
    // 빈도수가 다르면 빈도수 내림차순으로 정렬
    if (cf2->frequency != cf1->frequency)
        return cf2->frequency - cf1->frequency;
    else
        return 0; // 빈도수가 같으면 순서를 유지
}

/**
 * 문자열을 문자 빈도수에 따라 내림차순으로 정렬하는 함수
 * 빈도수가 같은 문자는 임의의 순서로 배치될 수 있음
 * 
 * @param s 정렬할 입력 문자열
 * @return 빈도수에 따라 정렬된 새로운 문자열 (동적 할당, 호출자가 메모리 해제 필요)
 */
char* frequencySort(char* s) {
    if (s == NULL) {
        // 입력 문자열이 NULL인 경우 NULL 반환
        return NULL;
    }

    // 각 ASCII 문자(0-127)의 빈도수를 저장할 배열 초기화
    int freq[128] = {0};

    // 문자열의 길이를 구함
    int len = strlen(s);
    
    // 문자열을 순회하며 각 문자의 빈도수를 계산
    for (int i = 0; i < len; i++) {
        freq[(unsigned char)s[i]]++;
    }

    // 빈도수가 0보다 큰 문자들을 저장할 배열과 고유 문자 수를 추적할 변수
    CharFreq charFreqs[128];
    int distinct = 0; // 고유 문자 수

    // 모든 ASCII 문자를 순회하며 빈도수가 있는 문자들을 charFreqs 배열에 저장
    for (int i = 0; i < 128; i++) {
        if (freq[i] > 0) {
            charFreqs[distinct].character = (char)i;
            charFreqs[distinct].frequency = freq[i];
            distinct++;
        }
    }

    // charFreqs 배열을 빈도수 내림차순으로 정렬
    qsort(charFreqs, distinct, sizeof(CharFreq), compare);

    // 결과 문자열을 저장할 메모리 할당 (+1은 null 종료 문자)
    char *result = (char *)malloc((len + 1) * sizeof(char));
    if (result == NULL) {
        // 메모리 할당 실패 시 NULL 반환
        return NULL;
    }

    int pos = 0; // 결과 문자열의 현재 위치

    // 정렬된 문자 빈도수에 따라 결과 문자열을 구성
    for (int i = 0; i < distinct; i++) {
        for (int j = 0; j < charFreqs[i].frequency; j++) {
            result[pos++] = charFreqs[i].character;
        }
    }

    result[pos] = '\0'; // 문자열 끝에 null 종료 문자 추가

    return result; // 정렬된 문자열 반환
}

// 예제 사용 및 테스트를 위한 메인 함수
int main() {
    // 예제 1
    char s1[] = "tree";
    char *sorted1 = frequencySort(s1);
    printf("Input: \"%s\"\nOutput: \"%s\"\n\n", s1, sorted1);
    free(sorted1); // 동적으로 할당된 메모리 해제

    // 예제 2
    char s2[] = "cccaaa";
    char *sorted2 = frequencySort(s2);
    printf("Input: \"%s\"\nOutput: \"%s\"\n\n", s2, sorted2);
    free(sorted2); // 동적으로 할당된 메모리 해제

    // 예제 3
    char s3[] = "Aabb";
    char *sorted3 = frequencySort(s3);
    printf("Input: \"%s\"\nOutput: \"%s\"\n\n", s3, sorted3);
    free(sorted3); // 동적으로 할당된 메모리 해제

    // 추가 테스트 케이스
    char s4[] = "banana";
    char *sorted4 = frequencySort(s4);
    printf("Input: \"%s\"\nOutput: \"%s\"\n\n", s4, sorted4);
    free(sorted4); // 동적으로 할당된 메모리 해제

    return 0;
}
