#include <stdio.h>
#include <stdlib.h>

// Define a structure for a singly linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert an element before another element
void insertBefore(struct Node** head, int newData, int targetData) {
    struct Node* newNode = createNode(newData);
    struct Node* current = *head;
    struct Node* prev = NULL;

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
        newNode->next = *head;
        *head = newNode;
    } else {
        prev->next = newNode;
        newNode->next = current;
    }
}

// Function to insert an element after another element
void insertAfter(struct Node** head, int newData, int targetData) {
    struct Node* newNode = createNode(newData);
    struct Node* current = *head;

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
void deleteElement(struct Node** head, int targetData) {
    struct Node* current = *head;
    struct Node* prev = NULL;

    while (current != NULL && current->data != targetData) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Element %d not found in the list\n", targetData);
        return;
    }

    if (prev == NULL) {
        *head = current->next;
    } else {
        prev->next = current->next;
    }

    free(current);
}

// Function to traverse and print the list
void traverseList(struct Node* head) {
    struct Node* current = head;
    printf("List: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to reverse the list
void reverseList(struct Node** head) {
    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* nextNode = NULL;

    while (current != NULL) {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }

    *head = prev;
}

// Function to sort the list (using bubble sort)
void sortList(struct Node** head) {
    struct Node* current;
    struct Node* temp;
    int swapped;

    if (*head == NULL) {
        return;
    }

    do {
        swapped = 0;
        current = *head;

        while (current->next != NULL) {
            if (current->data > current->next->data) {
                // Swap the data
                temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = 1;
            }
            current = current->next;
        }
    } while (swapped);
}

// Function to delete every alternate node in the list
void deleteAlternateNodes(struct Node** head) {
    struct Node* current = *head;
    struct Node* nextNode;

    if (*head == NULL) {
        return;
    }

    while (current != NULL && current->next != NULL) {
        nextNode = current->next;
        current->next = nextNode->next;
        free(nextNode);
        current = current->next;
    }
}

// Function to insert an element in a sorted list while maintaining order
void insertInSorted(struct Node** head, int newData) {
    struct Node* newNode = createNode(newData);
    struct Node* current = *head;
    struct Node* prev = NULL;

    while (current != NULL && current->data < newData) {
        prev = current;
        current = current->next;
    }

    if (prev == NULL) {
        newNode->next = *head;
        *head = newNode;
    } else {
        newNode->next = current;
        prev->next = newNode;
    }
}

int main() {
    struct Node* head = NULL;
    int choice;
    int data, targetData;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert an element before another element\n");
        printf("2. Insert an element after another element\n");
        printf("3. Delete a given element from the list\n");
        printf("4. Traverse the list\n");
        printf("5. Reverse the list\n");
        printf("6. Sort the list\n");
        printf("7. Delete every alternate node in the list\n");
        printf("8. Insert an element in a sorted list\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &data);
                printf("Enter the element before which to insert: ");
                scanf("%d", &targetData);
                insertBefore(&head, data, targetData);
                break;
            case 2:
                printf("Enter the element to insert: ");
                scanf("%d", &data);
                printf("Enter the element after which to insert: ");
                scanf("%d", &targetData);
                insertAfter(&head, data, targetData);
                break;
            case 3:
                printf("Enter the element to delete: ");
                scanf("%d", &data);
                deleteElement(&head, data);
                break;
            case 4:
                traverseList(head);
                break;
            case 5:
                reverseList(&head);
                break;
            case 6:
                sortList(&head);
                break;
            case 7:
                deleteAlternateNodes(&head);
                break;
            case 8:
                printf("Enter the element to insert in the sorted list: ");
                scanf("%d", &data);
                insertInSorted(&head, data);
                break;
            case 9:
                // Exit the program
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

