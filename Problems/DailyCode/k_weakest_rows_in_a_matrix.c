#include <stdio.h>
#include <stdlib.h>

/**
 * 구조체 정의: 각 행의 인덱스와 군인의 수를 저장
 */
typedef struct {
    int index;      // 행의 인덱스
    int soldiers;   // 행에 있는 군인의 수
} RowInfo;

/**
 * 비교 함수: qsort에서 사용, 군인의 수가 적은 순으로 정렬
 * 만약 군인의 수가 같다면, 인덱스가 작은 순으로 정렬
 */
int compareRows(const void* a, const void* b) {
    RowInfo* rowA = (RowInfo*)a;
    RowInfo* rowB = (RowInfo*)b;
    
    // 군인의 수를 기준으로 비교
    if (rowA->soldiers != rowB->soldiers) {
        return rowA->soldiers - rowB->soldiers; // 군인의 수가 적은 순
    }
    // 군인의 수가 같을 경우, 인덱스를 기준으로 비교
    return rowA->index - rowB->index; // 인덱스가 작은 순
}

/**
 * 함수 설명:
 * 주어진 이진 행렬 mat에서 가장 약한 k개의 행의 인덱스를 반환합니다.
 * 약한 순서는 군인의 수가 적은 순, 군인의 수가 같을 경우 인덱스가 작은 순으로 정의됩니다.
 * 
 * @param mat 이진 행렬 (1: 군인, 0: 민간인)
 * @param matSize 행렬의 행 수
 * @param matColSize 각 행의 열 수 (모든 행의 열 수는 동일하다고 가정)
 * @param k 가장 약한 k개의 행을 선택
 * @param returnSize 반환할 배열의 크기를 저장할 포인터
 * @return 가장 약한 k개의 행의 인덱스를 담은 동적 배열 (호출자가 메모리를 해제해야 함)
 */
int* kWeakestRows(int** mat, int matSize, int* matColSize, int k, int* returnSize) {
    // 행 정보를 저장할 배열 동적 할당
    RowInfo* rows = (RowInfo*)malloc(matSize * sizeof(RowInfo));
    if (rows == NULL) {
        // 메모리 할당 실패 시
        *returnSize = 0;
        return NULL;
    }
    
    // 각 행에 대해 군인의 수를 계산하고 행 정보를 저장
    for (int i = 0; i < matSize; i++) {
        int soldiers = 0;
        // 각 행의 열을 순회하며 1의 개수를 센다
        for (int j = 0; j < matColSize[i]; j++) {
            if (mat[i][j] == 1) {
                soldiers++;
            } else {
                // 군인이 더 이상 없으므로 중단
                break;
            }
        }
        rows[i].index = i;
        rows[i].soldiers = soldiers;
    }
    
    // 행 정보를 군인의 수 기준으로 정렬
    qsort(rows, matSize, sizeof(RowInfo), compareRows);
    
    // 결과 배열 동적 할당
    int* result = (int*)malloc(k * sizeof(int));
    if (result == NULL) {
        // 메모리 할당 실패 시
        free(rows);
        *returnSize = 0;
        return NULL;
    }
    
    // 정렬된 행 정보에서 처음 k개의 인덱스를 결과 배열에 저장
    for (int i = 0; i < k; i++) {
        result[i] = rows[i].index;
    }
    
    // 반환할 배열의 크기를 설정
    *returnSize = k;
    
    // 동적 할당된 행 정보 배열 해제
    free(rows);
    
    return result;
}

/**
 * 테스트를 위한 메인 함수
 * 실제 사용 시에는 이 부분을 제거하고 LeetCode 등 온라인 저지에서 실행하면 됩니다.
 */
int main() {
    // 예제 1
    int mat1_data[][5] = {
        {1,1,0,0,0},
        {1,1,1,1,0},
        {1,0,0,0,0},
        {1,1,0,0,0},
        {1,1,1,1,1}
    };
    int* mat1[5];
    for (int i = 0; i < 5; i++) {
        mat1[i] = mat1_data[i];
    }
    int mat1ColSize[5] = {5,5,5,5,5};
    int returnSize1;
    int* result1 = kWeakestRows(mat1, 5, mat1ColSize, 3, &returnSize1);
    printf("예제 1 출력: [");
    for (int i = 0; i < returnSize1; i++) {
        printf("%d", result1[i]);
        if (i != returnSize1 -1) printf(",");
    }
    printf("]\n"); // 예상 출력: [2,0,3]
    free(result1);
    
    // 예제 2
    int mat2_data[][4] = {
        {1,0,0,0},
        {1,1,1,1},
        {1,0,0,0},
        {1,0,0,0}
    };
    int* mat2[4];
    for (int i = 0; i < 4; i++) {
        mat2[i] = mat2_data[i];
    }
    int mat2ColSize[4] = {4,4,4,4};
    int returnSize2;
    int* result2 = kWeakestRows(mat2, 4, mat2ColSize, 2, &returnSize2);
    printf("예제 2 출력: [");
    for (int i = 0; i < returnSize2; i++) {
        printf("%d", result2[i]);
        if (i != returnSize2 -1) printf(",");
    }
    printf("]\n"); // 예상 출력: [0,2]
    free(result2);
    
    // 추가 테스트 케이스 1
    int mat3_data[][3] = {
        {1,1,1},
        {1,1,0},
        {1,0,0},
        {0,0,0},
        {1,1,1}
    };
    int* mat3[5];
    for (int i = 0; i < 5; i++) {
        mat3[i] = mat3_data[i];
    }
    int mat3ColSize[5] = {3,3,3,3,3};
    int returnSize3;
    int* result3 = kWeakestRows(mat3, 5, mat3ColSize, 2, &returnSize3);
    printf("추가 테스트 케이스 1 출력: [");
    for (int i = 0; i < returnSize3; i++) {
        printf("%d", result3[i]);
        if (i != returnSize3 -1) printf(",");
    }
    printf("]\n"); // 예상 출력: [3,2]
    free(result3);
    
    return 0;
}
