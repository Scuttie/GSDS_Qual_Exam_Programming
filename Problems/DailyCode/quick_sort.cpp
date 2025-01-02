#include <iostream>
#include <vector>

// 프로그램 설명:
// 이 프로그램은 Quick Sort 알고리즘을 구현하여 주어진 배열을 오름차순으로 정렬합니다.
// Quick Sort는 분할 정복(Divide and Conquer) 알고리즘으로, 배열을 피벗을 기준으로 두 부분으로 나누어
// 각각의 부분을 재귀적으로 정렬합니다.
// 이 구현에서는 마지막 요소를 피벗으로 사용하여, 피벗보다 작거나 같은 요소는 왼쪽에, 큰 요소는 오른쪽에 배치합니다.

// partition 함수 설명:
// 주어진 배열에서 피벗을 기준으로 요소들을 재배치하고, 피벗의 최종 위치를 반환합니다.
// 모든 피벗보다 작거나 같은 요소는 피벗의 왼쪽에, 큰 요소는 오른쪽에 위치하게 됩니다.
int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // 마지막 요소를 피벗으로 선택
    int i = low - 1;       // 피벗보다 작거나 같은 요소의 최종 위치를 추적

    for (int j = low; j < high; ++j) {
        // 현재 요소가 피벗보다 작거나 같으면
        if (arr[j] <= pivot) {
            ++i; // 작은 요소의 위치를 하나 증가시킴
            std::swap(arr[i], arr[j]); // 현재 요소를 작은 요소의 위치로 이동
        }
    }

    // 피벗을 작은 요소의 다음 위치로 이동시킴
    std::swap(arr[i + 1], arr[high]);
    return i + 1; // 피벗의 최종 위치 반환
}

// quickSort 함수 설명:
// 주어진 배열을 재귀적으로 Quick Sort 알고리즘을 사용하여 정렬합니다.
// low는 현재 정렬할 부분 배열의 시작 인덱스, high는 끝 인덱스를 나타냅니다.
void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        // 배열을 피벗을 기준으로 분할하고 피벗의 위치를 가져옴
        int pi = partition(arr, low, high);

        // 피벗의 왼쪽 부분 배열을 재귀적으로 정렬
        quickSort(arr, low, pi - 1);

        // 피벗의 오른쪽 부분 배열을 재귀적으로 정렬
        quickSort(arr, pi + 1, high);
    }
}

// 배열을 출력하는 헬퍼 함수
void printArray(const std::vector<int>& arr) {
    for (const auto& num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

// 메인 함수: Quick Sort 구현 및 테스트
int main() {
    // 테스트 케이스 1:
    // Input: [4, 1, 3, 9, 7]
    // Expected Output: [1, 3, 4, 7, 9]
    std::vector<int> arr1 = {4, 1, 3, 9, 7};
    std::cout << "Test Case 1:" << std::endl;
    std::cout << "Input: ";
    printArray(arr1);
    quickSort(arr1, 0, arr1.size() - 1);
    std::cout << "Sorted Output: ";
    printArray(arr1);
    std::cout << "Expected Output: 1 3 4 7 9" << std::endl;
    std::cout << ( (arr1 == std::vector<int>{1, 3, 4, 7, 9}) ? "PASS" : "FAIL" ) << std::endl;
    std::cout << "----------------------------------------" << std::endl;

    // 테스트 케이스 2:
    // Input: [2, 1, 6, 10, 4, 1, 3, 9, 7]
    // Expected Output: [1, 1, 2, 3, 4, 6, 7, 9, 10]
    std::vector<int> arr2 = {2, 1, 6, 10, 4, 1, 3, 9, 7};
    std::cout << "Test Case 2:" << std::endl;
    std::cout << "Input: ";
    printArray(arr2);
    quickSort(arr2, 0, arr2.size() - 1);
    std::cout << "Sorted Output: ";
    printArray(arr2);
    std::cout << "Expected Output: 1 1 2 3 4 6 7 9 10" << std::endl;
    std::cout << ( (arr2 == std::vector<int>{1, 1, 2, 3, 4, 6, 7, 9, 10}) ? "PASS" : "FAIL" ) << std::endl;
    std::cout << "----------------------------------------" << std::endl;

    // 테스트 케이스 3:
    // Input: [5, 5, 5, 5]
    // Expected Output: [5, 5, 5, 5]
    std::vector<int> arr3 = {5, 5, 5, 5};
    std::cout << "Test Case 3:" << std::endl;
    std::cout << "Input: ";
    printArray(arr3);
    quickSort(arr3, 0, arr3.size() - 1);
    std::cout << "Sorted Output: ";
    printArray(arr3);
    std::cout << "Expected Output: 5 5 5 5" << std::endl;
    std::cout << ( (arr3 == std::vector<int>{5, 5, 5, 5}) ? "PASS" : "FAIL" ) << std::endl;
    std::cout << "----------------------------------------" << std::endl;

    // 추가 테스트 케이스 4:
    // Input: [10, 7, 8, 9, 1, 5]
    // Expected Output: [1, 5, 7, 8, 9, 10]
    std::vector<int> arr4 = {10, 7, 8, 9, 1, 5};
    std::cout << "Test Case 4:" << std::endl;
    std::cout << "Input: ";
    printArray(arr4);
    quickSort(arr4, 0, arr4.size() - 1);
    std::cout << "Sorted Output: ";
    printArray(arr4);
    std::cout << "Expected Output: 1 5 7 8 9 10" << std::endl;
    std::cout << ( (arr4 == std::vector<int>{1, 5, 7, 8, 9, 10}) ? "PASS" : "FAIL" ) << std::endl;
    std::cout << "----------------------------------------" << std::endl;

    // 추가 테스트 케이스 5:
    // Input: [3]
    // Expected Output: [3]
    std::vector<int> arr5 = {3};
    std::cout << "Test Case 5:" << std::endl;
    std::cout << "Input: ";
    printArray(arr5);
    quickSort(arr5, 0, arr5.size() - 1);
    std::cout << "Sorted Output: ";
    printArray(arr5);
    std::cout << "Expected Output: 3" << std::endl;
    std::cout << ( (arr5 == std::vector<int>{3}) ? "PASS" : "FAIL" ) << std::endl;
    std::cout << "----------------------------------------" << std::endl;

    // 추가 테스트 케이스 6:
    // Input: [12, 11, 13, 5, 6, 7]
    // Expected Output: [5, 6, 7, 11, 12, 13]
    std::vector<int> arr6 = {12, 11, 13, 5, 6, 7};
    std::cout << "Test Case 6:" << std::endl;
    std::cout << "Input: ";
    printArray(arr6);
    quickSort(arr6, 0, arr6.size() - 1);
    std::cout << "Sorted Output: ";
    printArray(arr6);
    std::cout << "Expected Output: 5 6 7 11 12 13" << std::endl;
    std::cout << ( (arr6 == std::vector<int>{5, 6, 7, 11, 12, 13}) ? "PASS" : "FAIL" ) << std::endl;
    std::cout << "----------------------------------------" << std::endl;

    return 0; // 프로그램 종료
}

/*
프로그램 실행 결과:

Test Case 1:
Input: 4 1 3 9 7 
Sorted Output: 1 3 4 7 9 
Expected Output: 1 3 4 7 9
PASS
----------------------------------------
Test Case 2:
Input: 2 1 6 10 4 1 3 9 7 
Sorted Output: 1 1 2 3 4 6 7 9 10 
Expected Output: 1 1 2 3 4 6 7 9 10
PASS
----------------------------------------
Test Case 3:
Input: 5 5 5 5 
Sorted Output: 5 5 5 5 
Expected Output: 5 5 5 5
PASS
----------------------------------------
Test Case 4:
Input: 10 7 8 9 1 5 
Sorted Output: 1 5 7 8 9 10 
Expected Output: 1 5 7 8 9 10
PASS
----------------------------------------
Test Case 5:
Input: 3 
Sorted Output: 3 
Expected Output: 3
PASS
----------------------------------------
Test Case 6:
Input: 12 11 13 5 6 7 
Sorted Output: 5 6 7 11 12 13 
Expected Output: 5 6 7 11 12 13
PASS
----------------------------------------
*/

// 추가 설명:

/*
1. **Quick Sort 알고리즘 이해**:
    - Quick Sort는 분할 정복(Divide and Conquer) 방식의 정렬 알고리즘입니다.
    - 배열을 피벗을 기준으로 두 부분으로 분할하고, 각각의 부분을 재귀적으로 정렬합니다.
    - 피벗을 선택하는 방법에 따라 성능이 달라질 수 있습니다. 이 구현에서는 마지막 요소를 피벗으로 사용합니다.

2. **partition 함수**:
    - 피벗을 배열의 마지막 요소로 선택합니다.
    - 배열을 순회하면서 피벗보다 작거나 같은 요소를 찾아서 왼쪽으로 이동시킵니다.
    - 최종적으로 피벗을 적절한 위치에 배치하고, 피벗의 인덱스를 반환합니다.
    - 이 과정을 통해 피벗을 기준으로 배열이 두 부분으로 분할됩니다.

3. **quickSort 함수**:
    - 재귀적으로 배열의 부분을 정렬합니다.
    - base case는 `low < high`가 아닐 때로, 이 경우 함수는 종료됩니다.
    - partition 함수를 호출하여 피벗의 위치를 찾고, 피벗의 왼쪽과 오른쪽 부분을 각각 재귀적으로 정렬합니다.

4. **테스트 케이스**:
    - 다양한 테스트 케이스를 통해 Quick Sort 함수의 정확성을 검증합니다.
    - 예제 입력 외에도 추가적인 테스트 케이스를 포함하여 다양한 상황에서 함수가 올바르게 동작하는지 확인합니다.

5. **시간 및 공간 복잡도**:
    - **시간 복잡도**:
        - 평균적으로 O(N log N) 시간 복잡도를 가집니다.
        - 최악의 경우 O(N²) 시간 복잡도를 가질 수 있습니다. (이미 정렬된 배열 등에 대해 피벗을 선택할 때 발생)
    - **공간 복잡도**:
        - O(log N) 공간 복잡도를 가집니다. (재귀 호출 스택의 깊이)

6. **추가 최적화**:
    - 피벗 선택을 랜덤하게 하여 최악의 경우를 피할 수 있습니다.
    - 비재귀적인 Quick Sort 구현을 통해 스택 오버플로우를 방지할 수 있습니다.
    - 이 구현에서는 사용자 요구에 따라 마지막 요소를 피벗으로 사용하였으므로, 추가적인 최적화는 적용하지 않았습니다.

7. **C++의 STL 활용**:
    - C++에서는 `std::sort`와 같은 STL 정렬 함수를 사용할 수 있지만, 이번 문제는 Quick Sort의 구현을 직접 요구하였으므로 수동으로 구현하였습니다.

이 코드는 주어진 배열을 Quick Sort 알고리즘을 사용하여 오름차순으로 정확하게 정렬하며, 다양한 테스트 케이스를 통해 올바른 동작을 확인할 수 있습니다.
