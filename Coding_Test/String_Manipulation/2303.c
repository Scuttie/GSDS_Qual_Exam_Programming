#include <stdio.h>
#include <stdlib.h>

//////////////////////////////////////////
// 노드 구조체 정의
//////////////////////////////////////////
typedef struct Node {
    int data;
    struct Node* next;
} Node;

//////////////////////////////////////////
// 유틸(도움) 함수들
//////////////////////////////////////////

// 리스트의 길이를 구한다.
int length_of_list(Node* s) {
    int len = 0;
    while (s) {
        len++;
        s = s->next;
    }
    return len;
}

// 리스트에서 index 번째 노드를 반환 (0-based).
// 범위 넘어가면 NULL 반환.
Node* get_node(Node* s, int index) {
    int i = 0;
    while (s && i < index) {
        s = s->next;
        i++;
    }
    return s;  // s가 NULL 이거나 i==index 가 되면 반환
}

//////////////////////////////////////////
// (a) print_list(s)
//     연결 리스트를 [x,y,z] 형태로 출력
//////////////////////////////////////////
void print_list(Node* s) {
    printf("[");
    while (s) {
        printf("%d", s->data);
        if (s->next) {
            printf(",");
        }
        s = s->next;
    }
    printf("]");
}

//////////////////////////////////////////
// (b) palindrome(s)
//     s가 팰린드롬이면 1, 아니면 0 리턴
//////////////////////////////////////////
int palindrome(Node* s) {
    int len = length_of_list(s);
    // 양끝에서부터 비교
    for (int i = 0; i < len / 2; i++) {
        Node* left  = get_node(s, i);
        Node* right = get_node(s, len - 1 - i);
        if (!left || !right) {
            // 인덱스가 잘못되었다면 팰린드롬 아님
            return 0;
        }
        if (left->data != right->data) {
            return 0;
        }
    }
    return 1;
}

//////////////////////////////////////////
// (c) sub_list(s, t)
//     "연속된 부분 리스트"로서 s가 t에 포함되어 있으면 1, 아니면 0
//////////////////////////////////////////
int sub_list(Node* s, Node* t) {
    // s가 NULL 이면, 빈 리스트를 부분리스트로 볼지 말지는
    // 문제 해석에 따라 다를 수 있으나, 여기서는
    // "빈 리스트는 항상 부분리스트" 로 가정하여 1 리턴
    if (s == NULL) {
        return 1;
    }

    // t에서 시작점을 하나씩 옮겨가며 s와 매칭이 되는지 확인
    while (t) {
        Node* p1 = s;
        Node* p2 = t;
        // 두 리스트를 한 칸씩 비교
        while (p1 && p2 && p1->data == p2->data) {
            p1 = p1->next;
            p2 = p2->next;
        }
        // p1을 끝까지 다 봤다면 s를 모두 매칭했다는 뜻
        if (!p1) {
            return 1;
        }
        // 다음 위치에서 다시 시도
        t = t->next;
    }
    return 0;
}

//////////////////////////////////////////
// (d) max_palindromes(s)
//     s의 "모든 팰린드롬 부분리스트 중, 더 큰 팰린드롬의 부분이 되지 않는" 
//     sub-list 들을 전부 찾아서 출력.
//
//     - 여기서는 겹치는(오버랩되는) 부분리스트도 전부 고려
//     - 출력 형식: [[...],[...],[...]] 처럼 
//       각 최대 팰린드롬 부분리스트를 차례대로 찍는다.
//////////////////////////////////////////

// 구간 표현용 구조체
typedef struct {
    int start;
    int end;
} Range;

// 부분리스트 [start..end]가 다른 [S..E]에 "포함"되는지 검사
//  => (S <= start && end <= E)이면 포함되는 것.
int contained_in(Range small, Range big) {
    return (big.start <= small.start && small.end <= big.end);
}

void max_palindromes(Node* s) {
    int n = length_of_list(s);
    // 1) 모든 팰린드롬 부분구간 [i..j] 찾기
    Range* candidates = (Range*)malloc(sizeof(Range) * n * n);
    int count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            // i..j 부분리스트가 팰린드롬인지 확인
            // 팰린드롬이면 candidates[count++] = (i,j);
            // 팰린드롬 판정은 palindrome( subList )을 써야 하는데,
            // subList를 실제로 만들지 않고도 기존 함수 재활용 가능.
            // 여기서는 편의를 위해 아래와 같이 직접 검사하거나,
            // 혹은 임시 연결리스트를 만들어 palindrome(...)을 써도 된다.

            // 직접 검사 버전 (노드 이동):
            int len_sub = j - i + 1;
            int is_pal = 1;  // 일단 팰린드롬 가정
            for (int k = 0; k < len_sub / 2; k++) {
                Node* left  = get_node(s, i + k);
                Node* right = get_node(s, j - k);
                if (!left || !right || (left->data != right->data)) {
                    is_pal = 0;
                    break;
                }
            }
            if (is_pal) {
                candidates[count].start = i;
                candidates[count].end   = j;
                count++;
            }
        }
    }

    // 2) 더 큰 팰린드롬 범위에 "완전히 포함"되는 후보들은 제거
    //    즉, [i..j]가 [p..q]에 포함될 경우 [i..j]는 제외.
    //    간단히 말해 candidates를 하나씩 비교하면서
    //    포함관계가 있으면 '버려야 할지' 체크
    int* valid = (int*)malloc(sizeof(int) * count);
    for (int i = 0; i < count; i++) {
        valid[i] = 1;  // 처음엔 모두 살아있다고 가정
    }

    for (int i = 0; i < count; i++) {
        if (!valid[i]) continue;  // 이미 제외된 경우
        for (int j = 0; j < count; j++) {
            if (i == j) continue;
            if (!valid[j]) continue;
            // i번 구간이 j번 구간에 포함되는가?
            if (contained_in(candidates[i], candidates[j])) {
                // 단, 자기 자신이 아니라, j 구간이 더 '크거나 같은' 경우
                int len_i = candidates[i].end - candidates[i].start + 1;
                int len_j = candidates[j].end - candidates[j].start + 1;
                if (len_j >= len_i && (i != j)) {
                    // i 구간은 더 큰 팰린드롬의 부분이므로 제외
                    valid[i] = 0;
                    break;
                }
            }
        }
    }

    // 3) 살아남은 팰린드롬 구간들만 출력
    //    문제 예시처럼 [[...],[...],[...]] 형태로 가정
    printf("[");
    int firstPrinted = 1; // 출력 형식 제어용
    for (int i = 0; i < count; i++) {
        if (!valid[i]) continue;
        // 구간 candidates[i] 출력
        if (!firstPrinted) {
            printf(", ");  // 구분자
        } else {
            firstPrinted = 0;
        }
        // 부분리스트 실제 출력 => [start..end]
        printf("[");
        for (int idx = candidates[i].start; idx <= candidates[i].end; idx++) {
            Node* cur = get_node(s, idx);
            printf("%d", cur->data);
            if (idx < candidates[i].end) {
                printf(",");
            }
        }
        printf("]");
    }
    printf("]\n");

    // 동적 할당한 메모리 해제
    free(candidates);
    free(valid);
}

//////////////////////////////////////////
// 아래는 사용 예시를 보여주는 main 함수
// (테스트 용도로만 작성; 문제 제출 시에는
//  요구 사항에 맞춰 필요한 부분만 제출)
//////////////////////////////////////////
int main(void) {
    // 예시: 연결리스트 [3,7,6,8] 만들기
    Node* n1 = (Node*)malloc(sizeof(Node));
    Node* n2 = (Node*)malloc(sizeof(Node));
    Node* n3 = (Node*)malloc(sizeof(Node));
    Node* n4 = (Node*)malloc(sizeof(Node));
    n1->data = 3; n1->next = n2;
    n2->data = 7; n2->next = n3;
    n3->data = 6; n3->next = n4;
    n4->data = 8; n4->next = NULL;

    printf("print_list: ");
    print_list(n1);
    printf("\n");

    printf("palindrome? %d\n", palindrome(n1)); // 팰린드롬 여부

    // 부분리스트 예시: s=[6,8], t=[3,7,6,8] -> 1 리턴 기대
    Node* s1 = n3; // [6,8]
    Node* t1 = n1; // [3,7,6,8]
    printf("sub_list([6,8],[3,7,6,8])? %d\n", sub_list(s1, t1));

    // max_palindromes 예시(간단):
    // 원소가 많을수록 팰린드롬 후보가 다양해짐
    printf("max_palindromes([3,7,6,8]): ");
    max_palindromes(n1);

    // 메모리 해제
    free(n1); free(n2); free(n3); free(n4);

    return 0;
}
