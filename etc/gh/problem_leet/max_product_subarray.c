#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

int maxProduct(int* nums, int numsSize) {
    if (numsSize == 0) return 0;

    int max_so_far = nums[0];
    int min_so_far = nums[0];
    int result = nums[0];

    for (int i = 1; i < numsSize; i++) {
        int num = nums[i];

        if (num < 0) {
            int temp = max_so_far;
            max_so_far = min_so_far;
            min_so_far = temp;
        }

        max_so_far = max(num, max_so_far * num);
        min_so_far = min(num, min_so_far * num);

        result = max(result, max_so_far);
    }

    return result;
}

int main() {
    int arr[] = {2, 3, -2, 4};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("최대 부분 배열 곱: %d\n", maxProduct(arr, size));  // 출력: 6

    int arr2[] = {-2, 0, -1};
    size = sizeof(arr2) / sizeof(arr2[0]);
    printf("최대 부분 배열 곱: %d\n", maxProduct(arr2, size));  // 출력: 0

    return 0;
}
