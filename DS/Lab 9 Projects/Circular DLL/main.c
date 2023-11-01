#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;};

struct Node* head = NULL;

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("No memory\n");}

    newNode->data = data;
    newNode->next = newNode;
    newNode->prev = newNode;
    return newNode;}

void insertEnd(int data) {
    struct Node* newNode = createNode(data);
    if (head==NULL) {
        head = newNode;}
    else {
        struct Node* last = head->prev;
        last->next = newNode;
        newNode->prev = last;
        newNode->next = head;
        head->prev = newNode;
    }
}

void deleteElement(int data) {

    struct Node* current = head;
    while (current->data != data) {
        current = current->next;
        if (current == head) {
            printf("Element not found");}
    }

    current->prev->next = current->next;
    current->next->prev = current->prev;

    if (current == head) {
        head = current->next;}

    free(current);}

void traverseList() {
    struct Node* current = head;
    if (head == NULL) {
        printf("Nothing to Print");}

    do {
        printf("%d <-> ", current->data);
        current = current->next;
    } while (current != head);
    printf("%d\n",head->data);
}

int main() {
    int choice, data;

    while (1) {
        printf("Menu:\n");
        printf("1. Insert an element\n");
        printf("2. Delete an element\n");
        printf("3. Display the list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &data);
                insertEnd(data);
                break;
            case 2:
                printf("Enter the element to delete: ");
                scanf("%d", &data);
                deleteElement(data);
                break;
            case 3:
                printf("Doubly Linked Circular List: ");
                traverseList();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
