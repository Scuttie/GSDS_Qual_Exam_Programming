#include <stdio.h>
#include <stdint.h>

// 프로그램 설명:
// 이 프로그램은 주어진 32비트 부호 없는 정수의 비트를 뒤집는 함수를 구현합니다.
// 예를 들어, 입력이 00000010100101000001111010011100 (43261596)일 경우,
// 출력은 00111001011110000010100101000000 (964176192)가 됩니다.

// 함수 설명:
// uint32_t reverseBits(uint32_t n);
// - n: 비트를 뒤집을 32비트 부호 없는 정수
// - 반환값: 비트가 뒤집힌 32비트 부호 없는 정수

uint32_t reverseBits(uint32_t n) {
    uint32_t reversed = 0; // 뒤집힌 비트를 저장할 변수 초기화
    
    for(int i = 0; i < 32; i++) {
        reversed <<= 1;            // reversed를 왼쪽으로 1비트 이동
        reversed |= (n & 1);       // n의 현재 최하위 비트를 reversed에 추가
        n >>= 1;                    // n을 오른쪽으로 1비트 이동하여 다음 비트 준비
    }
    
    return reversed; // 뒤집힌 비트를 반환
}

// 최적화된 버전 (여러 번 호출 시):
// 만약 reverseBits 함수가 여러 번 호출될 경우, 미리 각 바이트의 뒤집힌 값을 저장하는
// 조회 테이블을 사용하여 성능을 향상시킬 수 있습니다.
// 아래는 조회 테이블을 사용하는 최적화된 버전입니다.

uint32_t reverseBitsOptimized(uint32_t n) {
    // 256 크기의 조회 테이블 생성 (각 바이트의 비트를 뒤집은 값)
    static uint8_t reverseByteTable[256];
    static int tableInitialized = 0;
    
    if (!tableInitialized) {
        for(int i = 0; i < 256; i++) {
            uint8_t b = (uint8_t)i;
            uint8_t rev = 0;
            for(int j = 0; j < 8; j++) {
                rev <<= 1;
                rev |= (b & 1);
                b >>= 1;
            }
            reverseByteTable[i] = rev;
        }
        tableInitialized = 1;
    }
    
    // 각 바이트를 뒤집은 후, 적절한 위치에 배치하여 최종 결과를 생성
    return ((uint32_t)reverseByteTable[n & 0xFF] << 24) |
           ((uint32_t)reverseByteTable[(n >> 8) & 0xFF] << 16) |
           ((uint32_t)reverseByteTable[(n >> 16) & 0xFF] << 8) |
           ((uint32_t)reverseByteTable[(n >> 24) & 0xFF]);
}

// 테스트를 위한 메인 함수
int main() {
    // 예제 1:
    // Input: n = 00000010100101000001111010011100 (43261596)
    // Output:    964176192 (00111001011110000010100101000000)
    uint32_t n1 = 0b00000010100101000001111010011100;
    uint32_t expected1 = 964176192;
    uint32_t result1 = reverseBits(n1);
    printf("Test Case 1:\n");
    printf("Input:    %u (0x%08X)\n", n1, n1);
    printf("Expected: %u (0x%08X)\n", expected1, expected1);
    printf("Output:   %u (0x%08X)\n", result1, result1);
    printf("%s\n\n", (result1 == expected1) ? "PASS" : "FAIL");
    
    // 예제 2:
    // Input: n = 11111111111111111111111111111101 (4294967293)
    // Output:   3221225471 (10111111111111111111111111111111)
    uint32_t n2 = 0b11111111111111111111111111111101;
    uint32_t expected2 = 3221225471;
    uint32_t result2 = reverseBits(n2);
    printf("Test Case 2:\n");
    printf("Input:    %u (0x%08X)\n", n2, n2);
    printf("Expected: %u (0x%08X)\n", expected2, expected2);
    printf("Output:   %u (0x%08X)\n", result2, result2);
    printf("%s\n\n", (result2 == expected2) ? "PASS" : "FAIL");
    
    // 추가 테스트 케이스 1:
    // Input: n = 0 (00000000000000000000000000000000)
    // Output: 0 (00000000000000000000000000000000)
    uint32_t n3 = 0;
    uint32_t expected3 = 0;
    uint32_t result3 = reverseBits(n3);
    printf("Test Case 3:\n");
    printf("Input:    %u (0x%08X)\n", n3, n3);
    printf("Expected: %u (0x%08X)\n", expected3, expected3);
    printf("Output:   %u (0x%08X)\n", result3, result3);
    printf("%s\n\n", (result3 == expected3) ? "PASS" : "FAIL");
    
    // 추가 테스트 케이스 2:
    // Input: n = 1 (00000000000000000000000000000001)
    // Output: 2147483648 (10000000000000000000000000000000)
    uint32_t n4 = 1;
    uint32_t expected4 = 2147483648;
    uint32_t result4 = reverseBits(n4);
    printf("Test Case 4:\n");
    printf("Input:    %u (0x%08X)\n", n4, n4);
    printf("Expected: %u (0x%08X)\n", expected4, expected4);
    printf("Output:   %u (0x%08X)\n", result4, result4);
    printf("%s\n\n", (result4 == expected4) ? "PASS" : "FAIL");
    
    // 추가 테스트 케이스 3:
    // Input: n = 43261596 (00000010100101000001111010011100)
    // Output: 964176192 (00111001011110000010100101000000)
    uint32_t n5 = 43261596;
    uint32_t expected5 = 964176192;
    uint32_t result5 = reverseBits(n5);
    printf("Test Case 5:\n");
    printf("Input:    %u (0x%08X)\n", n5, n5);
    printf("Expected: %u (0x%08X)\n", expected5, expected5);
    printf("Output:   %u (0x%08X)\n", result5, result5);
    printf("%s\n\n", (result5 == expected5) ? "PASS" : "FAIL");
    
    // 추가 테스트 케이스 4:
    // Input: n = 4294967295 (11111111111111111111111111111111)
    // Output: 4294967295 (11111111111111111111111111111111)
    uint32_t n6 = 4294967295;
    uint32_t expected6 = 4294967295;
    uint32_t result6 = reverseBits(n6);
    printf("Test Case 6:\n");
    printf("Input:    %u (0x%08X)\n", n6, n6);
    printf("Expected: %u (0x%08X)\n", expected6, expected6);
    printf("Output:   %u (0x%08X)\n", result6, result6);
    printf("%s\n\n", (result6 == expected6) ? "PASS" : "FAIL");
    
    // 최적화된 버전 테스트:
    printf("Optimized Function Tests:\n");
    
    uint32_t result1_opt = reverseBitsOptimized(n1);
    printf("Test Case 1 Optimized Output: %u (0x%08X) %s\n",
           result1_opt, result1_opt, (result1_opt == expected1) ? "PASS" : "FAIL");
    
    uint32_t result2_opt = reverseBitsOptimized(n2);
    printf("Test Case 2 Optimized Output: %u (0x%08X) %s\n",
           result2_opt, result2_opt, (result2_opt == expected2) ? "PASS" : "FAIL");
    
    uint32_t result3_opt = reverseBitsOptimized(n3);
    printf("Test Case 3 Optimized Output: %u (0x%08X) %s\n",
           result3_opt, result3_opt, (result3_opt == expected3) ? "PASS" : "FAIL");
    
    uint32_t result4_opt = reverseBitsOptimized(n4);
    printf("Test Case 4 Optimized Output: %u (0x%08X) %s\n",
           result4_opt, result4_opt, (result4_opt == expected4) ? "PASS" : "FAIL");
    
    uint32_t result5_opt = reverseBitsOptimized(n5);
    printf("Test Case 5 Optimized Output: %u (0x%08X) %s\n",
           result5_opt, result5_opt, (result5_opt == expected5) ? "PASS" : "FAIL");
    
    uint32_t result6_opt = reverseBitsOptimized(n6);
    printf("Test Case 6 Optimized Output: %u (0x%08X) %s\n",
           result6_opt, result6_opt, (result6_opt == expected6) ? "PASS" : "FAIL");
    
    return 0; // 프로그램 종료
}

/*
프로그램 설명:

1. **reverseBits 함수**:
    - 이 함수는 주어진 32비트 부호 없는 정수 `n`의 비트를 뒤집습니다.
    - `reversed` 변수를 사용하여 결과를 저장합니다.
    - 32번의 반복을 통해 `n`의 각 비트를 오른쪽에서 왼쪽으로 하나씩 추출하여 `reversed`에 왼쪽으로 이동시키면서 추가합니다.
    - 최종적으로 `reversed`는 `n`의 비트가 뒤집힌 값을 가지게 됩니다.

2. **reverseBitsOptimized 함수**:
    - 이 최적화된 함수는 여러 번 호출될 경우 성능을 향상시키기 위해 미리 각 바이트의 뒤집힌 값을 저장하는 조회 테이블을 사용합니다.
    - 최초 호출 시, 256 크기의 조회 테이블을 초기화하여 각 바이트(0~255)의 뒤집힌 값을 미리 계산합니다.
    - 이후, 입력 정수를 4개의 바이트로 나누어 각 바이트의 뒤집힌 값을 조회 테이블에서 가져와 적절한 위치에 배치하여 최종 결과를 생성합니다.
    - 이 방법은 각 바이트의 비트를 한 번만 뒤집으면 되므로, 여러 번 호출 시 효율적입니다.

3. **테스트 케이스**:
    - `main` 함수에서는 여러 테스트 케이스를 정의하고, 각 케이스에 대해 `reverseBits`와 `reverseBitsOptimized` 함수를 호출하여 결과를 검증합니다.
    - 각 테스트 케이스는 입력 값, 예상 출력 값, 실제 출력 값을 출력하며, 예상과 실제 결과가 일치하는지 확인합니다.
    - 추가 테스트 케이스를 통해 다양한 입력 상황을 검증합니다.

4. **출력 형식**:
    - 각 테스트 케이스는 입력 값과 예상 출력 값을 10진수와 16진수 형식으로 출력하여 비트 반전이 올바르게 이루어졌는지 쉽게 확인할 수 있습니다.
    - `PASS` 또는 `FAIL`을 출력하여 테스트 결과를 명확하게 표시합니다.

5. **메모리 관리**:
    - 이 프로그램은 동적 메모리를 사용하지 않으므로 별도의 메모리 해제가 필요하지 않습니다.
    - `reverseBitsOptimized` 함수 내의 조회 테이블은 `static`으로 선언되어 프로그램 종료 시 자동으로 해제됩니다.

### 최적화된 알고리즘 설명

- **조회 테이블 사용 이유**:
    - 비트 뒤집기 연산은 연산자 우선순위나 반복문을 사용하여 직접 구현할 수 있지만, 여러 번 호출될 경우 성능이 저하될 수 있습니다.
    - 조회 테이블을 사용하면 각 바이트의 비트를 미리 뒤집어 저장해 두고, 입력 정수를 4개의 바이트로 나누어 각 바이트의 뒤집힌 값을 빠르게 가져와 조합할 수 있습니다.
    - 이는 반복적인 비트 연산을 줄여주어 성능을 크게 향상시킵니다.

- **조회 테이블 초기화**:
    - 프로그램이 시작될 때 256 크기의 배열을 초기화하여 각 바이트의 비트를 뒤집은 값을 저장합니다.
    - 예를 들어, 바이트 `00000001` (1)은 `10000000` (128)로 뒤집힙니다.

- **최적화된 비트 뒤집기**:
    - 입력 정수를 4개의 바이트로 나눈 후, 각 바이트를 조회 테이블에서 뒤집힌 값으로 교체하고, 최종 결과를 조합합니다.
    - 이렇게 하면 각 바이트의 비트를 한 번만 뒤집어도 되므로, 전체 연산량이 감소합니다.

### 시간 및 공간 복잡도

1. **reverseBits 함수**:
    - **시간 복잡도**: O(1) — 항상 32번의 반복을 수행합니다.
    - **공간 복잡도**: O(1) — 추가적인 공간을 상수 크기로 사용합니다.

2. **reverseBitsOptimized 함수**:
    - **시간 복잡도**: O(1) — 조회 테이블을 사용하는 경우, 바이트당 고정된 시간 내에 비트를 뒤집습니다.
    - **공간 복잡도**: O(1) — 256 크기의 조회 테이블을 상수 공간으로 사용합니다.

### 추가 고려 사항

- **Endianess**:
    - 이 구현은 바이트 순서(Endianess)에 독립적입니다. 비트의 순서를 정확하게 뒤집기 때문에, 시스템의 바이트 순서와 무관하게 동일한 결과를 보장합니다.

- **부호 없는 정수 사용 이유**:
    - 비트 연산은 부호 없는 정수에서 명확하게 정의됩니다. 부호 있는 정수의 경우, 최상위 비트가 부호 비트로 사용되므로 비트 뒤집기 결과가 예상과 다를 수 있습니다.
    - 따라서 이 문제에서는 부호 없는 정수를 사용하는 것이 적절합니다.

- **함수의 범용성**:
    - `reverseBits` 함수는 모든 32비트 부호 없는 정수에 대해 올바른 결과를 보장합니다.
    - 추가적인 테스트 케이스를 통해 다양한 입력에 대해 정확성을 검증하는 것이 좋습니다.

이 코드는 주어진 32비트 부호 없는 정수의 비트를 효과적으로 뒤집으며, 여러 번 호출될 경우 최적화된 방법을 사용하여 성능을 향상시킬 수 있습니다. 다양한 테스트 케이스를 통해 함수의 정확성과 효율성을 확인할 수 있습니다.
