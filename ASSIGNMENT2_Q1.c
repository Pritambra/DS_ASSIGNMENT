#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

struct node* create_node();
void add_first(int data);
void display();
void add_last(int data);
void add_at_specific_pos(int data, int pos);
int count_nodes();
void delete_first();
void delete_last();
void delete_at_specific_pos(int pos);
void selection_sort();

int main() {
    add_first(10);
    add_first(20);
    add_first(30);
    add_last(40);
    add_last(60);
    add_first(50);
    add_last(80);
    add_first(70);
    add_first(100);
    
    printf("Original List:\n");
    display();
    
   
    selection_sort();
    printf("Sorted List:\n");
    display();

    return 0;
}

struct node* create_node()
 {
    struct node *ptr = (struct node*) malloc(sizeof(struct node));
    ptr->data = 0;
    ptr->next = NULL;
    return ptr;
}

void add_first(int data) 
{
    struct node *ptr = create_node();
    ptr->data = data;
    if (head == NULL) {
        head = ptr;
    } else {
        ptr->next = head;
        head = ptr;
    }
}

void display()
 {
    if (head == NULL) {
        printf("List is Empty!\n");
    } else {
        struct node *trav = head;
        printf("Head");
        while (trav != NULL) {
            printf(" -> %d", trav->data);
            trav = trav->next;
        }
    }
    printf("\n");
}

void add_last(int data) 
{
    struct node *ptr = create_node();
    ptr->data = data;
    if (head == NULL) {
        head = ptr;
    } else {
        struct node *trav = head;
        while (trav->next != NULL) {
            trav = trav->next;
        }
        trav->next = ptr;
    }
}

void add_at_specific_pos(int data, int pos) 
{
    if (head == NULL) {
        if (pos == 1) {
            add_first(data);
        } else {
            printf("Invalid position\n");
        }
    } else if (pos == 1) {
        add_first(data);
    } else if (pos == count_nodes() + 1) {
        add_last(data);
    } else if (pos < 1 || pos > count_nodes() + 1) {
        printf("Invalid position!\n");
    } else {
        struct node *ptr = create_node();
        ptr->data = data;
        struct node *trav = head;
        for (int i = 1; i < pos - 1; i++) {
            trav = trav->next;
        }
        ptr->next = trav->next;
        trav->next = ptr;
    }
}

int count_nodes()
 {
    int count = 0;
    struct node *trav = head;
    while (trav != NULL) {
        count++;
        trav = trav->next;
    }
    return count;
}

void delete_first() 
{
    if (head == NULL) {
        printf("List is Empty!\n");
    } else if (head->next == NULL) {
        free(head);
        head = NULL;
    } else {
        struct node *temp = head;
        head = head->next;
        free(temp);
    }
}

void delete_last() {
    if (head == NULL) {
        printf("List is Empty!\n");
    } else if (head->next == NULL) {
        free(head);
        head = NULL;
    } else {
        struct node *trav = head;
        while (trav->next->next != NULL) {
            trav = trav->next;
        }
        free(trav->next);
        trav->next = NULL;
    }
}

void delete_at_specific_pos(int pos) {
    if (head == NULL) {
        printf("List is Empty!\n");
    } else if (pos == 1) {
        delete_first();
    } else if (pos == count_nodes()) {
        delete_last();
    } else if (pos < 1 || pos > count_nodes()) {
        printf("Invalid position!\n");
    } else {
        struct node *trav = head;
        for (int i = 1; i < pos - 1; i++) {
            trav = trav->next;
        }
        struct node *temp = trav->next;
        trav->next = temp->next;
        free(temp);
    }
}


void selection_sort() 
{
    if (head == NULL) return; 

    struct node *current = head;

    while (current != NULL) {
        struct node *min_node = current;
        struct node *next_node = current->next;

        while (next_node != NULL) {
            if (next_node->data < min_node->data) {
                min_node = next_node;
            }
            next_node = next_node->next;
        }

        
        if (min_node != current) {
            int temp = current->data;
            current->data = min_node->data;
            min_node->data = temp;
        }

        current = current->next;
    }
}
