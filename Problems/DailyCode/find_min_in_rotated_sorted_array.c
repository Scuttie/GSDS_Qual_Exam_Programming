#include <stdio.h>
#include <stdlib.h>

/*
문제 설명:

정렬된 길이 n의 배열이 1부터 n번 회전되었습니다. 예를 들어, 배열 nums = [0,1,4,4,5,6,7]은 다음과 같이 회전될 수 있습니다:

- 4번 회전 후: [4,5,6,7,0,1,4]
- 7번 회전 후: [0,1,4,4,5,6,7]

배열 [a[0], a[1], a[2], ..., a[n-1]]을 1번 회전하면 [a[n-1], a[0], a[1], a[2], ..., a[n-2]]가 됩니다.

중복 요소가 포함될 수 있는 정렬된 회전 배열 nums가 주어질 때, 이 배열의 최소 요소를 반환하세요.

가능한 한 전체 연산 단계를 줄여야 합니다.

예제 1:

입력: nums = [1,3,5]
출력: 1

예제 2:

입력: nums = [2,2,2,0,1]
출력: 0

제약 사항:

- n == nums.length
- 1 <= n <= 5000
- -5000 <= nums[i] <= 5000
- nums는 정렬된 후 1번 이상 n번 회전된 배열입니다.

함수 정의:

int findMin(int* nums, int numsSize) {
    
}
*/

/* 
알고리즘 설명:

이 문제는 정렬된 배열이 회전된 형태이며, 중복 요소가 포함될 수 있기 때문에 이진 탐색을 약간 수정하여 해결할 수 있습니다.

1. 왼쪽 포인터(left)와 오른쪽 포인터(right)를 배열의 양 끝에 설정합니다.
2. 반복문을 통해 left가 right보다 작을 때까지 다음을 수행합니다:
    a. 중간 인덱스(mid)를 계산합니다.
    b. nums[mid]와 nums[right]를 비교합니다.
        - 만약 nums[mid] < nums[right]라면, 최소값은 left부터 mid까지에 존재하므로 right를 mid로 이동합니다.
        - 만약 nums[mid] > nums[right]라면, 최소값은 mid+1부터 right까지에 존재하므로 left를 mid+1로 이동합니다.
        - 만약 nums[mid] == nums[right]라면, 중복이므로 right를 하나 줄여 검색 범위를 좁힙니다.
3. 최종적으로 left가 가리키는 위치의 값이 최소값입니다.

이 접근 방식은 최악의 경우 O(n) 시간이 걸릴 수 있지만, 중복이 적을 경우 평균적으로 O(log n) 시간 복잡도를 가집니다.
*/

int findMin(int* nums, int numsSize) {
    if (numsSize == 0) {
        // 배열이 비어있는 경우 -1 반환 (문제의 제약 조건에 따르면 N >= 1이므로 실제로는 발생하지 않음)
        return -1;
    }
    
    int left = 0;
    int right = numsSize - 1;
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        
        if (nums[mid] < nums[right]) {
            // 최소값은 left부터 mid까지에 존재
            right = mid;
        }
        else if (nums[mid] > nums[right]) {
            // 최소값은 mid+1부터 right까지에 존재
            left = mid + 1;
        }
        else {
            // nums[mid]와 nums[right]가 같으므로, right를 하나 줄여 검색 범위를 좁힘
            right--;
        }
    }
    
    return nums[left];
}

// 테스트를 위한 헬퍼 함수
void testFindMin(int* nums, int numsSize, int expected) {
    int result = findMin(nums, numsSize);
    printf("Input: [");
    for(int i = 0; i < numsSize; i++) {
        printf("%d%s", nums[i], (i < numsSize - 1) ? "," : "");
    }
    printf("], Expected Output: %d, Actual Output: %d -> %s\n", expected, result, (result == expected) ? "PASS" : "FAIL");
}

int main() {
    // 테스트 케이스 목록
    struct TestCase {
        int nums[5000];  // 최대 크기 5000 (문제의 제약 조건에 따라)
        int numsSize;
        int expected;
    } testCases[] = {
        // 예제 테스트 케이스 1:
        { .nums = {1, 3, 5}, .numsSize = 3, .expected = 1 },
        
        // 예제 테스트 케이스 2:
        { .nums = {2, 2, 2, 0, 1}, .numsSize = 5, .expected = 0 },
        
        // 추가 테스트 케이스 3:
        { .nums = {4,5,6,7,0,1,2}, .numsSize = 7, .expected = 0 },
        
        // 추가 테스트 케이스 4:
        { .nums = {10,1,10,10,10}, .numsSize = 5, .expected = 1 },
        
        // 추가 테스트 케이스 5:
        { .nums = {3,3,1,3}, .numsSize = 4, .expected = 1 },
        
        // 추가 테스트 케이스 6:
        { .nums = {1}, .numsSize = 1, .expected = 1 },
        
        // 추가 테스트 케이스 7:
        { .nums = {2,1}, .numsSize = 2, .expected = 1 },
        
        // 추가 테스트 케이스 8:
        { .nums = {1,1,1,1,1}, .numsSize = 5, .expected = 1 },
        
        // 추가 테스트 케이스 9:
        { .nums = {10,10,10,10,10,10}, .numsSize = 6, .expected = 10 },
        
        // 추가 테스트 케이스 10:
        { .nums = {-1,0,1,2,3}, .numsSize = 5, .expected = -1 },
    };
    
    int numTests = sizeof(testCases) / sizeof(testCases[0]);
    
    // 각 테스트 케이스에 대해 결과를 검증
    for(int i = 0; i < numTests; i++) {
        testFindMin(testCases[i].nums, testCases[i].numsSize, testCases[i].expected);
    }
    
    return 0;
}

/*
프로그램 실행 결과:

Input: [1,3,5], Expected Output: 1, Actual Output: 1 -> PASS
Input: [2,2,2,0,1], Expected Output: 0, Actual Output: 0 -> PASS
Input: [4,5,6,7,0,1,2], Expected Output: 0, Actual Output: 0 -> PASS
Input: [10,1,10,10,10], Expected Output: 1, Actual Output: 1 -> PASS
Input: [3,3,1,3], Expected Output: 1, Actual Output: 1 -> PASS
Input: [1], Expected Output: 1, Actual Output: 1 -> PASS
Input: [2,1], Expected Output: 1, Actual Output: 1 -> PASS
Input: [1,1,1,1,1], Expected Output: 1, Actual Output: 1 -> PASS
Input: [10,10,10,10,10,10], Expected Output: 10, Actual Output: 10 -> PASS
Input: [-1,0,1,2,3], Expected Output: -1, Actual Output: -1 -> PASS
*/
