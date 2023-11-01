#include <stdio.h>
#include <stdlib.h>

// Define a structure for a doubly linked list node
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* head1 = NULL;
struct Node* head2 = NULL;

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to insert a node at the end of a doubly linked list
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}

// Function to concatenate two doubly linked lists
void concatenateLists(struct Node** list1, struct Node* list2) {
    if (*list1 == NULL) {
        *list1 = list2;
    } else if (list2 != NULL) {
        struct Node* current = *list1;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = list2;
        list2->prev = current;
    }
}

// Function to print a doubly linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    // Create and populate the first list
    insertEnd(&head1, 1);
    insertEnd(&head1, 2);
    insertEnd(&head1, 3);

    // Create and populate the second list
    insertEnd(&head2, 4);
    insertEnd(&head2, 5);

    printf("First List: ");
    printList(head1);

    printf("Second List: ");
    printList(head2);

    // Concatenate the second list to the first list
    concatenateLists(&head1, head2);

    printf("Concatenated List: ");
    printList(head1);

    return 0;
}
