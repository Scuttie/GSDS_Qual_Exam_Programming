#include <stdio.h>
#include <stdlib.h>

// 배열에 요소가 있는지 확인하는 함수
int contains(int* arr, int size, int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            return 1; // 요소가 이미 배열에 존재
        }
    }
    return 0; // 요소가 배열에 존재하지 않음
}

// 두 배열의 합집합을 구하는 함수
int* union_arrays(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    // 최악의 경우 크기는 nums1Size + nums2Size
    int* result = (int*)malloc(sizeof(int) * (nums1Size + nums2Size));
    int resultIndex = 0;

    // nums1의 모든 요소를 결과 배열에 추가
    for (int i = 0; i < nums1Size; i++) {
        if (!contains(result, resultIndex, nums1[i])) {
            result[resultIndex++] = nums1[i];
        }
    }

    // nums2의 모든 요소를 결과 배열에 추가 (중복 제외)
    for (int i = 0; i < nums2Size; i++) {
        if (!contains(result, resultIndex, nums2[i])) {
            result[resultIndex++] = nums2[i];
        }
    }

    *returnSize = resultIndex;
    return result;
}

// main 함수
int main() {
    int nums1[] = {1, 2, 2, 3};
    int nums2[] = {2, 3, 4, 5};
    int nums1Size = sizeof(nums1) / sizeof(nums1[0]);
    int nums2Size = sizeof(nums2) / sizeof(nums2[0]);

    int returnSize;
    int* result = union_arrays(nums1, nums1Size, nums2, nums2Size, &returnSize);

    printf("Union of the arrays: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result); // 동적 메모리 해제

    return 0;
}
