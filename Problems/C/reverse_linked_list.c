// 주어진 Linked List를 reverse하는 코드입니다.
// prev, curr, next Node Pointer를 관리하면서 주어진 Linked List를 순회하며 Node 순서를 뒤집어야 합니다.

#include <stdio.h>
#include <stdlib.h>

/* Linked list node structure */
struct Node {
    int data;
    struct Node* next;
};

typedef struct Node Node;

/* Function to create a new node */
struct Node * createNode(struct Node * newNode, int data){
  newNode = (struct Node *) malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}


int main(int argc, char* argv[])
{  
  int length = argc - 1;

  /* Create a linked list from input integers */
  int k = 1;
  struct Node * head = NULL;
  struct Node * prev = NULL;
  struct Node * curr = NULL;

  for (int k = 1; k <= length; k++) {
    curr = createNode(curr, atoi(argv[k]));

    if (k > 1)
      prev->next = curr;
    else
      head = curr;

    prev = curr;
  }

  /* Write your code here */	
  
  //순회에 쓰일 포인터 생성
  struct Node * prev2 = NULL;
  struct Node * curr2 = NULL;
  struct Node * next = NULL;

  //length만큼 돌면서 반복
  for (int k = 1; k <= length; k++){
    //첫번째일 경우
    if (k == 1){
      //curr를 head로 적용
      curr2 = head;
    }
    //다음 Step을 대비해두기
    //next는 현재의 next로 업데이트
    next = curr2->next;
    
    //실제 뒤집는 과정
    //현재의 next를 prev로 업데이트 (순서 뒤집기)
    curr2->next = prev2;

    //다음 Step으로 넘어가기
    //prev를 curr로 업데이트
    prev2 = curr2;
    //curr은 미리 저장한 next로 업데이트
    curr2 = next;
  }

  //루프를 빠져나오면 curr은 NULL로, prev가 마지막 노드로 돼있을 것이므로 prev를 head로 지정
  head = prev2;

  /* Do not modify below */	
  /* Print reversed linked list */
  curr = head;
  while (curr){
    printf("%d ", curr->data);
    curr = curr->next;
  }
  return 0;
}


