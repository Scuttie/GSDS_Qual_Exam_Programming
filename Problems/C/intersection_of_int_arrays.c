#include <stdio.h>
#include <stdlib.h>

// 요소를 배열에서 제거하는 함수
void remove_element(int* arr, int* size, int index) {
    for (int i = index; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
}

// 배열에서 특정 요소의 인덱스를 찾는 함수
int find_index(int* arr, int size, int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1; // 요소를 찾지 못한 경우
}

// 두 배열의 교집합을 구하는 함수
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int* result = (int*)malloc(sizeof(int) * (nums1Size < nums2Size ? nums1Size : nums2Size)); 
    int resultIndex = 0;

    if (nums1Size < nums2Size) {
        for (int i = 0; i < nums1Size; i++) {
            int index = find_index(nums2, nums2Size, nums1[i]);
            if (index != -1) {
                result[resultIndex++] = nums1[i];
                remove_element(nums2, &nums2Size, index);
            }
        }
    } else {
        for (int i = 0; i < nums2Size; i++) {
            int index = find_index(nums1, nums1Size, nums2[i]);
            if (index != -1) {
                result[resultIndex++] = nums2[i];
                remove_element(nums1, &nums1Size, index);
            }
        }
    }

    *returnSize = resultIndex;
    return result;
}

// main 함수
int main() {
    int nums1[] = {1, 2, 2, 1};
    int nums2[] = {2, 2};
    int nums1Size = sizeof(nums1) / sizeof(nums1[0]);
    int nums2Size = sizeof(nums2) / sizeof(nums2[0]);

    int returnSize;
    int* result = intersect(nums1, nums1Size, nums2, nums2Size, &returnSize);

    printf("Intersection of the arrays: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result); // 동적 메모리 해제

    return 0;
}
