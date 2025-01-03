#include <stdio.h>
#include <stdlib.h>

/**
 * 배열의 첫 k개 요소를 뒤집는 함수.
 * 
 * @param arr 뒤집을 배열
 * @param k 뒤집을 요소의 개수
 */
void flip(int* arr, int k) {
    int i = 0, j = k - 1;
    while (i < j) {
        // arr[i]와 arr[j]를 교환
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }
}

/**
 * 서브 배열 arr[0...end]에서 최대 요소의 인덱스를 찾는 함수.
 * 
 * @param arr 배열
 * @param end 서브 배열의 마지막 인덱스
 * @return 최대 요소의 인덱스
 */
int findMaxIndex(int* arr, int end) {
    int max_idx = 0;
    for (int i = 1; i <= end; i++) {
        if (arr[i] > arr[max_idx]) {
            max_idx = i;
        }
    }
    return max_idx;
}

/**
 * 팬케이크 정렬을 수행하는 함수.
 * 
 * @param arr 정렬할 배열
 * @param arrSize 배열의 크기
 * @param returnSize 반환할 플립 시퀀스의 크기를 저장할 포인터
 * @return 플립 시퀀스를 담은 배열 (호출자가 메모리를 해제해야 함)
 */
int* pancakeSort(int* arr, int arrSize, int* returnSize) {
    // 플립 시퀀스를 저장할 배열 동적 할당. 최대 플립 횟수는 2 * arrSize
    int* flips = (int*)malloc(2 * arrSize * sizeof(int));
    if (flips == NULL) {
        *returnSize = 0;
        return NULL; // 메모리 할당 실패 시
    }
    
    int flip_count = 0; // 플립 횟수 초기화

    // 배열의 끝에서부터 시작하여 정렬을 진행
    for (int current_size = arrSize; current_size > 1; current_size--) {
        // 현재 서브 배열에서 최대 요소의 인덱스를 찾음
        int max_idx = findMaxIndex(arr, current_size - 1);
        
        // 최대 요소가 이미 올바른 위치에 있는 경우 건너뜀
        if (max_idx == current_size - 1) {
            continue;
        }
        
        // 최대 요소가 첫 번째 위치에 있지 않다면, 먼저 첫 번째 위치로 플립
        if (max_idx != 0) {
            flip(arr, max_idx + 1); // 첫 max_idx + 1개 요소 뒤집기
            flips[flip_count++] = max_idx + 1; // 플립 시퀀스에 기록
        }
        
        // 이제 현재 서브 배열 전체를 뒤집어 최대 요소를 올바른 위치로 이동
        flip(arr, current_size);
        flips[flip_count++] = current_size; // 플립 시퀀스에 기록
    }
    
    // 반환할 플립 시퀀스의 크기 설정
    *returnSize = flip_count;
    
    // 실제 필요한 만큼의 메모리를 다시 할당하여 결과 저장
    int* result = (int*)malloc(flip_count * sizeof(int));
    if (result == NULL) {
        free(flips);
        *returnSize = 0;
        return NULL; // 메모리 할당 실패 시
    }
    for (int i = 0; i < flip_count; i++) {
        result[i] = flips[i];
    }
    free(flips); // 초기 큰 배열 메모리 해제
    
    return result; // 플립 시퀀스 반환
}

/**
 * 배열을 출력하는 헬퍼 함수.
 * 
 * @param arr 출력할 배열
 * @param size 배열의 크기
 */
void printArray(int* arr, int size) {
    printf("[");
    for(int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if(i != size -1) {
            printf(",");
        }
    }
    printf("]\n");
}

/**
 * 팬케이크 정렬 함수를 테스트하기 위한 메인 함수.
 */
int main() {
    // 예제 1:
    int arr1[] = {3, 2, 4, 1};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int returnSize1;
    int* flips1 = pancakeSort(arr1, size1, &returnSize1);
    printf("예제 1:\nInput: [3,2,4,1]\nOutput: ");
    printArray(flips1, returnSize1); // 예상 출력: [4,2,4,3]
    free(flips1); // 할당된 메모리 해제

    // 예제 2:
    int arr2[] = {1, 2, 3};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int returnSize2;
    int* flips2 = pancakeSort(arr2, size2, &returnSize2);
    printf("\n예제 2:\nInput: [1,2,3]\nOutput: ");
    printArray(flips2, returnSize2); // 예상 출력: []
    free(flips2); // 할당된 메모리 해제

    // 예제 3:
    int arr3[] = {1};
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    int returnSize3;
    int* flips3 = pancakeSort(arr3, size3, &returnSize3);
    printf("\n예제 3:\nInput: [1]\nOutput: ");
    printArray(flips3, returnSize3); // 예상 출력: []
    free(flips3); // 할당된 메모리 해제

    // 예제 4:
    int arr4[] = {1, 2, 3, 4, 5};
    int size4 = sizeof(arr4) / sizeof(arr4[0]);
    int returnSize4;
    int* flips4 = pancakeSort(arr4, size4, &returnSize4);
    printf("\n예제 4:\nInput: [1,2,3,4,5]\nOutput: ");
    printArray(flips4, returnSize4); // 예상 출력: []
    free(flips4); // 할당된 메모리 해제

    // 추가 테스트 케이스 1:
    int arr5[] = {4, 3, 2, 1};
    int size5 = sizeof(arr5) / sizeof(arr5[0]);
    int returnSize5;
    int* flips5 = pancakeSort(arr5, size5, &returnSize5);
    printf("\n추가 테스트 케이스 1:\nInput: [4,3,2,1]\nOutput: ");
    printArray(flips5, returnSize5); // 예상 출력: [4]
    free(flips5); // 할당된 메모리 해제

    // 추가 테스트 케이스 2:
    int arr6[] = {3, 2, 1, 4};
    int size6 = sizeof(arr6) / sizeof(arr6[0]);
    int returnSize6;
    int* flips6 = pancakeSort(arr6, size6, &returnSize6);
    printf("\n추가 테스트 케이스 2:\nInput: [3,2,1,4]\nOutput: ");
    printArray(flips6, returnSize6); // 예상 출력: [3,4]
    free(flips6); // 할당된 메모리 해제

    return 0;
}
