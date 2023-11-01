#include <stdio.h>
#include <stdlib.h>

// Define a structure for a singly linked list node
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;};

struct Node* head = NULL;

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


void insertrear(int data) {
    struct Node *newNode = createNode(data);

    if (head == NULL) {
        // If the list is empty, set the new node as the head.
        head = newNode;
    } else {
        struct Node *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}


void insertat(int data,int pos){
    struct Node *newNode = createNode(data);
    struct Node *current = head;

    for(int i=0;i<pos,current!=NULL;i++,current=current->next);
            current->next=newNode;
            current->next->prev=newNode;
            newNode->next=current->next;
            newNode->prev=current;
    }

// Function to insert an element before another element
void insertBefore(int newData, int targetData) {
    struct Node *newNode = createNode(newData);
    struct Node *current = head;
    struct Node *prev = NULL;

    while (current != NULL && current->data != targetData) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Element %d not found in the list\n", targetData);
        free(newNode);
        return;
    }

    if (prev == NULL) {
        newNode->next = head;
        head = newNode;
    } else {
        prev->next = newNode;
        newNode->next = current;
    }
}

// Function to insert an element after another element
void insertAfter(int newData, int targetData) {
    struct Node *newNode = createNode(newData);
    struct Node *current = head;

    while (current != NULL && current->data != targetData) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Element %d not found in the list\n", targetData);
        free(newNode);
        return;
    }

    newNode->next = current->next;
    current->next = newNode;
}

// Function to delete a given element from the list
void deleteat(int pos) {
    struct Node *current = head;
    struct Node *prev = NULL;
    int i=0;
    while (current != NULL &&i != pos) {
        prev = current;
        current = current->next;
        i++;}

    if (prev == NULL) {
        head = current->next;
    } else {
        prev->next = current->next;
    }

    free(current);
}


void deleterear() {
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    struct Node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    if (current->prev != NULL) {
        current->prev->next = NULL;
    } else {
        // If there is only one element in the list, update the head.
        head = NULL;
    }
    free(current);
}


// Function to traverse and print the list
void traverseList() {
    struct Node* current = head;
    printf("List: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to reverse the list
void reverselist() {
    struct Node* temp = NULL;
    struct Node* current = head;

    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != NULL) {
        head = temp->prev;
    }
}


int main() {
    int choice;
    int data, pos;

    while (1) {
        printf("Menu:\n");
        printf("1. Insert an element at rear \n");
        printf("2. Delete an element at rear\n");
        printf("3. Insert an element at a given position\n");
        printf("4. Delete an element at a given position\n");
        printf("5. Insert an element before another element\n");
        printf("6. Insert an element after another element\n");
        printf("7. Traverse the list\n");
        printf("8. Reverse the list\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &data);
                insertrear(data);
                traverseList();
                break;
            case 2:
                deleterear();
                traverseList();
                break;
            case 3:
                printf("Enter the element to insert: ");
                scanf("%d", &data);
                printf("Enter the element position");
                scanf("%d", &pos);
                insertat(data, pos);
                traverseList();
                break;
            case 4:
                printf("Enter the element position");
                scanf("%d", &pos);
                deleteat(pos);
                traverseList();
                break;
            case 5:
                printf("Enter the element to insert: ");
                scanf("%d", &data);
                printf("Enter the element before which to insert: ");
                scanf("%d", &pos);
                insertBefore(data, pos);
                traverseList();
                break;
            case 6:
                printf("Enter the element to insert: ");
                scanf("%d", &data);
                printf("Enter the element after which to insert: ");
                scanf("%d", &pos);
                insertAfter(data, pos);
                traverseList();
                break;
            case 7:
                traverseList();
                break;
            case 8:
                reverselist();
                traverseList();
                break;
            case 9:
                // Exit the program
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");

        }
    printf("\n");
    }

    return 0;
}

