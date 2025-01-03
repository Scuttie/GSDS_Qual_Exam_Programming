#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 구조체 정의: 각 숫자를 문자열로 저장
typedef struct {
    char* str; // 숫자를 문자열로 변환한 값
} NumStr;

// 두 문자열을 비교하는 함수: 내림차순 정렬을 위해 큰 조합이 먼저 오도록 함
int compare(const void* a, const void* b) {
    NumStr* numA = (NumStr*)a;
    NumStr* numB = (NumStr*)b;
    
    // 두 문자열을 합친 후 비교
    // 예: "3"과 "30"을 비교할 때 "330" vs "303"
    char combo1[20]; // 두 문자열을 합친 조합 1
    char combo2[20]; // 두 문자열을 합친 조합 2
    
    snprintf(combo1, sizeof(combo1), "%s%s", numA->str, numB->str);
    snprintf(combo2, sizeof(combo2), "%s%s", numB->str, numA->str);
    
    // 내림차순 정렬을 위해 combo2가 더 크면 양수 반환
    return strcmp(combo2, combo1);
}

/**
 * 숫자 배열을 가장 큰 숫자를 만들기 위해 정렬하고, 그 결과를 문자열로 반환하는 함수
 * 
 * @param nums 숫자 배열
 * @param numsSize 숫자 배열의 크기
 * @return 가장 큰 숫자를 나타내는 문자열 (동적 할당, 호출자가 메모리 해제 필요)
 */
char* largestNumber(int* nums, int numsSize) {
    // 숫자를 문자열로 변환하여 저장할 배열 생성
    NumStr* numStrs = (NumStr*)malloc(numsSize * sizeof(NumStr));
    if (numStrs == NULL) {
        // 메모리 할당 실패 시 NULL 반환
        return NULL;
    }
    
    // 각 숫자를 문자열로 변환
    for (int i = 0; i < numsSize; i++) {
        // 각 숫자는 최대 10자리 (0부터 10^9까지)
        // 추가로 null 종료 문자 1자리를 더함
        numStrs[i].str = (char*)malloc(12 * sizeof(char));
        if (numStrs[i].str == NULL) {
            // 메모리 할당 실패 시, 이전에 할당된 메모리 해제 후 NULL 반환
            for (int j = 0; j < i; j++) {
                free(numStrs[j].str);
            }
            free(numStrs);
            return NULL;
        }
        snprintf(numStrs[i].str, 12, "%d", nums[i]);
    }
    
    // qsort를 사용하여 내림차순 정렬
    qsort(numStrs, numsSize, sizeof(NumStr), compare);
    
    // 모든 숫자가 '0'인 경우 "0"을 반환
    if (numStrs[0].str[0] == '0') {
        // 모든 숫자가 '0'이므로 "0"을 반환
        char* result = (char*)malloc(2 * sizeof(char));
        if (result == NULL) {
            // 메모리 할당 실패 시
            for (int i = 0; i < numsSize; i++) {
                free(numStrs[i].str);
            }
            free(numStrs);
            return NULL;
        }
        result[0] = '0';
        result[1] = '\0';
        
        // 할당된 메모리 해제
        for (int i = 0; i < numsSize; i++) {
            free(numStrs[i].str);
        }
        free(numStrs);
        
        return result;
    }
    
    // 결과 문자열의 최대 길이를 계산
    int totalLength = 0;
    for (int i = 0; i < numsSize; i++) {
        totalLength += strlen(numStrs[i].str);
    }
    
    // 결과 문자열을 저장할 메모리 할당 (+1은 null 종료 문자)
    char* result = (char*)malloc((totalLength + 1) * sizeof(char));
    if (result == NULL) {
        // 메모리 할당 실패 시
        for (int i = 0; i < numsSize; i++) {
            free(numStrs[i].str);
        }
        free(numStrs);
        return NULL;
    }
    
    // 결과 문자열 초기화
    result[0] = '\0';
    
    // 정렬된 문자열을 순서대로 결과에 추가
    for (int i = 0; i < numsSize; i++) {
        strcat(result, numStrs[i].str);
        free(numStrs[i].str); // 더 이상 필요 없는 문자열 메모리 해제
    }
    
    free(numStrs); // 구조체 배열 메모리 해제
    
    return result; // 결과 문자열 반환
}

// 예제 사용 및 테스트를 위한 메인 함수
int main() {
    // 예제 1
    int nums1[] = {10, 2};
    int size1 = sizeof(nums1) / sizeof(nums1[0]);
    char* largest1 = largestNumber(nums1, size1);
    printf("Input: [10, 2]\nOutput: \"%s\"\n\n", largest1);
    free(largest1); // 동적으로 할당된 메모리 해제

    // 예제 2
    int nums2[] = {3, 30, 34, 5, 9};
    int size2 = sizeof(nums2) / sizeof(nums2[0]);
    char* largest2 = largestNumber(nums2, size2);
    printf("Input: [3, 30, 34, 5, 9]\nOutput: \"%s\"\n\n", largest2);
    free(largest2); // 동적으로 할당된 메모리 해제

    // 추가 테스트 케이스 1
    int nums3[] = {1};
    int size3 = sizeof(nums3) / sizeof(nums3[0]);
    char* largest3 = largestNumber(nums3, size3);
    printf("Input: [1]\nOutput: \"%s\"\n\n", largest3);
    free(largest3); // 동적으로 할당된 메모리 해제

    // 추가 테스트 케이스 2
    int nums4[] = {10, 0};
    int size4 = sizeof(nums4) / sizeof(nums4[0]);
    char* largest4 = largestNumber(nums4, size4);
    printf("Input: [10, 0]\nOutput: \"%s\"\n\n", largest4);
    free(largest4); // 동적으로 할당된 메모리 해제

    // 추가 테스트 케이스 3
    int nums5[] = {0, 0};
    int size5 = sizeof(nums5) / sizeof(nums5[0]);
    char* largest5 = largestNumber(nums5, size5);
    printf("Input: [0, 0]\nOutput: \"%s\"\n\n", largest5);
    free(largest5); // 동적으로 할당된 메모리 해제

    return 0;
}
