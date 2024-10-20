#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *prev;
    int data;
    struct node *next;
};

struct node *head = NULL;

void add_first(int data);
void forward_display();
void backward_display();
struct node* create_node(int data);
void insertion_sort();

int main() {
    add_first(10);
    add_first(30);
    add_first(15);

    printf("Original List:\n");
    forward_display();

    insertion_sort();
    printf("Sorted List:\n");
    forward_display();
    backward_display();

    return 0;
}

struct node* create_node(int data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Malloc Failed!\n");
        exit(1);
    }
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
}

void add_first(int data) {
    struct node *new_node = create_node(data);

    if (head == NULL) {
        head = new_node;
        new_node->next = head; // circular
        new_node->prev = head; // circular
    } else {
        new_node->next = head;
        new_node->prev = head->prev;
        head->prev->next = new_node;
        head->prev = new_node;
        head = new_node;
    }
}

void forward_display() {
    if (head == NULL) {
        printf("List is Empty!\n");
    } else {
        struct node *trav = head;
        printf("Head");
        do {
            printf(" -> %d", trav->data);
            trav = trav->next;
        } while (trav != head);
    }
    printf("\n");
}

void backward_display() {
    if (head == NULL) {
        printf("List is Empty!\n");
    } else {
        struct node *trav = head->prev;
        printf("Tail");
        do {
            printf(" -> %d", trav->data);
            trav = trav->prev;
        } while (trav != head->prev);
    }
    printf("\n");
}

void insertion_sort() {
    if (head == NULL || head->next == head) return; // Empty or single node case

    struct node *sorted = NULL; // Start with an empty sorted list
    struct node *current = head;

    do {
        struct node *next = current->next; // Store next node
        struct node *new_node = create_node(current->data);

        
        if (sorted == NULL) {
            sorted = new_node;
            sorted->next = sorted; // circular
            sorted->prev = sorted; // circular
        } else {
            struct node *trav = sorted;

            do
             {
                if (trav->data >= new_node->data) {
                    break;
                }
                trav = trav->next;
            } while (trav != sorted);

            new_node->next = trav;
            new_node->prev = trav->prev;
            trav->prev->next = new_node;
            trav->prev = new_node;

           
            if (trav == sorted && new_node->data < sorted->data)  
            {
                sorted = new_node; 
            }
        }
        current = next; 
    } while (current != head);

   
    head = sorted;
}
