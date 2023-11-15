#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new binary tree node
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert an element into a binary search tree
struct TreeNode* insertBST(struct TreeNode* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insertBST(root->left, data);
    } else if (data > root->data) {
        root->right = insertBST(root->right, data);
    }

    return root;
}

// Function to find the minimum value node in a binary search tree
struct TreeNode* findMin(struct TreeNode* node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

// Function to delete an element from a binary search tree
struct TreeNode* deleteBST(struct TreeNode* root, int data) {
    if (root == NULL) {
        return root;
    }

    if (data < root->data) {
        root->left = deleteBST(root->left, data);
    } else if (data > root->data) {
        root->right = deleteBST(root->right, data);
    } else {
        if (root->left == NULL) {
            struct TreeNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct TreeNode* temp = root->left;
            free(root);
            return temp;
        }

        struct TreeNode* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteBST(root->right, temp->data);
    }

    return root;
}

// Function to search for a given element in a binary search tree
int searchBST(struct TreeNode* root, int data) {
    if (root == NULL) {
        return 0;
    }

    if (data == root->data) {
        return 1;
    } else if (data < root->data) {
        return searchBST(root->left, data);
    } else {
        return searchBST(root->right, data);
    }
}

// Function for in-order traversal and printing the binary search tree
void inOrderTraversal(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }

    inOrderTraversal(root->left);
    printf("%d ", root->data);
    inOrderTraversal(root->right);
}

int main() {
    struct TreeNode* root = NULL;
    int choice, data;

    while (1) {
        printf("\nBinary Search Tree Operations:\n");
        printf("1. Insert an element\n");
        printf("2. Delete an element\n");
        printf("3. Search for an element\n");
        printf("4. Print the binary search tree\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &data);
                root = insertBST(root, data);
                break;
            case 2:
                printf("Enter the element to delete: ");
                scanf("%d", &data);
                root = deleteBST(root, data);
                break;
            case 3:
                printf("Enter the element to search for: ");
                scanf("%d", &data);
                if (searchBST(root, data)) {
                    printf("%d found in the tree.\n", data);
                } else {
                    printf("%d not found in the tree.\n", data);
                }
                break;
            case 4:
                printf("Binary Search Tree (In-order traversal): ");
                inOrderTraversal(root);
                printf("\n");
                break;
            case 5:
                // Free memory (assuming you have more complex tree and need to free it)
                return 0;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }
}
