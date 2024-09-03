#include <stdio.h>

int missingNumber(int* nums, int numsSize) {
    int n = numsSize;
    int total_sum = n * (n + 1) / 2;
    int array_sum = 0;

    for (int i = 0; i < numsSize; i++) {
        array_sum += nums[i];
    }

    return total_sum - array_sum;
}

int main() {
    int nums[] = {3, 0, 1};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    printf("Missing Number: %d\n", missingNumber(nums, numsSize));  // 출력: 2

    int nums2[] = {0, 1};
    numsSize = sizeof(nums2) / sizeof(nums2[0]);
    printf("Missing Number: %d\n", missingNumber(nums2, numsSize));  // 출력: 2

    int nums3[] = {9,6,4,2,3,5,7,0,1};
    numsSize = sizeof(nums3) / sizeof(nums3[0]);
    printf("Missing Number: %d\n", missingNumber(nums3, numsSize));  // 출력: 8

    return 0;
}
