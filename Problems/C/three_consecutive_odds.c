#include <stdio.h>
#include <stdbool.h>

bool threeConsecutiveOdds(int* arr, int arrSize) {
    // 배열의 길이가 3 미만이면 연속된 3개의 홀수가 있을 수 없으므로 false 반환
    if (arrSize < 3) {
        return false;
    }

    // 배열을 순회하면서 연속된 세 개의 홀수를 찾음
    for (int i = 0; i <= arrSize - 3; i++) {
        // 현재 숫자, 다음 숫자, 그 다음 숫자가 모두 홀수인지 확인
        if (arr[i] % 2 != 0 && arr[i+1] % 2 != 0 && arr[i+2] % 2 != 0) {
            return true;  // 연속된 세 개의 홀수를 찾으면 true 반환
        }
    }

    // 끝까지 연속된 세 개의 홀수를 찾지 못하면 false 반환
    return false;
}

int main() {
    int arr[] = {1, 6, 4, 8, 3, 5, 21};
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    bool result = threeConsecutiveOdds(arr, arrSize);

    if (result) {
        printf("The array contains three consecutive odd numbers.\n");
    } else {
        printf("The array does not contain three consecutive odd numbers.\n");
    }

    return 0;
}
