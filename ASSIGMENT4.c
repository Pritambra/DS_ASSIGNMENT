#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


struct Node* addNode(struct Node* head, int data) 
{
   
    if (head == NULL) {
        return createNode(data);
    }

    
    head->next = addNode(head->next, data);
    return head; 
}


void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}


int main() {
    struct Node* head = NULL;
    head = addNode(head, 10);
    head = addNode(head, 20);
    head = addNode(head, 30);
     head = addNode(head, 10);
    head = addNode(head, 20);
    head = addNode(head, 30);

    
    printList(head);

    
    return 0;
}
