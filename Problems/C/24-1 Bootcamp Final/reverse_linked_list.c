#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

typedef struct Node Node;

void reverse_list(Node** head) {
    /*Write your code below*/
    Node* prev = NULL;
    Node* curr = *head;
    Node* next = NULL;

    while (curr != NULL){
        next = curr -> next;
        curr -> next = prev;
        prev = curr; 
        curr = next;
    }

    *head = prev;
    
    ///////////////////////////
}

// Do not modify below
void append(Node** head, int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    Node* last = *head;
    new_node->data = data;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }

    last->next = new_node;
}

void print_list(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(int argc, char* argv[]) {
    Node* head = NULL;

    for(int i = 1; i < argc; i++){
        append(&head, atoi(argv[i]));
    }

    reverse_list(&head);
    print_list(head);

    return 0;
}
