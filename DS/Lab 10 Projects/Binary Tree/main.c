#include <stdio.h>
#include <stdlib.h>

struct Node{
int data;
struct Node* left;
struct Node* right};

struct Node* createNode (int data){
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node*));
if (newNode == NULL) {printf("No memory\n");}

newNode->data = data;
newNode->left = NULL;
newNode->right = NULL;
return newNode;}

struct Node* insertNode(struct Node* root, int data){
if(root==NULL) return createNode(data);
else if(root->left==NULL)

root->left=insertNode(root->left,data);
else root->right=insertNode(root->right,data);
return root;}

void inOrder(struct Node* root) {
struct Node* stack[100];
int top = -1;
struct Node* current = root;
while (current != NULL || top > -1) {
while (current != NULL){
        stack[++top] = current;
        current = current->left;}
current = stack[top--];
printf("%d ", current->data);
current = current->right;}
}

void preOrder(struct Node* root) {
if (root == NULL) return;
struct Node* stack[100];
int top = -1;
stack[++top] = root;

while (top != -1) {
struct Node* current = stack[top--];
printf("%d ", current->data);
if (current->right != NULL)
stack[++top] = current->right;
if (current->left != NULL)
stack[++top] = current->left;}
}

void postOrder(struct Node* root) {
if (root == NULL) return;

struct Node* current = root;
struct Node* prev = NULL;
struct Node* stack[100];
int top = -1;

do{
while (current != NULL) {
        stack[++top] = current;
        current = current->left;}
while (current == NULL && top != -1) {
        current = stack[top];
        if (current->right == NULL || current->right == prev) {
            printf("%d ", current->data);
            top--;
            prev = current;
            current = NULL;}
        else {current = current->right;}}
}while(top != -1);
}


int count(struct Node* root) {
if(root==NULL) return 0;
if (root->left==NULL&&root->right==NULL){return 1;}

return count(root->left)+count(root->right);
}

int maxDepth(struct Node* root) {
if (root == NULL) {
    return 0;
} else {
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    return (leftDepth>rightDepth)?(leftDepth + 1):(rightDepth + 1);
}
}



int printAncestors(struct Node* root, int target){
if (root==NULL) return 0;
if (root->data==target)return 1;
if(printAncestors(root->left, target)||printAncestors(root->right, target)) {
    printf("%d ", root->data);
    return 1;}

return 0;
}


void findParent(struct Node* node,int val, int parent){
if (node == NULL) return;
if (node->data == val) {
    return parent;}
else {
findParent(node->left, val, node->data);
    findParent(node->right, val, node->data);}
}





int main() {
struct TreeNode* root = NULL;

int choice, data, target;
int found;

do {
printf("\nBinary Tree Operations:\n");
printf("1. In-order Traversal\n");
printf("2. Post-order Traversal\n");
printf("3. Pre-order Traversal\n");
printf("4. Print Parent of Element\n");
printf("5. Print Depth of Tree\n");
printf("6. Print Ancestors of Element\n");
printf("7. Count Leaf Nodes\n");
printf("8. Insert Element\n");
printf("0. Exit\n");

printf("Enter your choice: ");
scanf("%d", &choice);

switch (choice) {
case 1:
    printf("In-order Traversal: ");
    inOrder(root);
    break;
case 2:
    printf("Post-order Traversal: ");
    postOrder(root);
    break;
case 3:
    printf("Pre-order Traversal: ");
    preOrder(root);
    break;
case 4:
    printf("Enter the element to find its parent: ");
    scanf("%d", &target);
    findParent(root, target,-1);
    break;
case 5:
    printf("Depth of the Tree: %d\n", maxDepth(root));
    break;
case 6:
    printf("Enter the element to find its ancestors: ");
    scanf("%d", &target);
    printf("Ancestors: ");
    found = printAncestors(root, target);
    if (!found)
        printf("Element not found in the tree.");
    printf("\n");
    break;
case 7:
    printf("Number of Leaf Nodes: %d\n", count(root));
    break;
case 8:
    printf("Enter the element to insert: ");
    scanf("%d", &data);
    root = insertNode(root, data);
    break;
case 0:
    printf("Exiting...\n");
    break;
default:
    printf("Invalid choice! Please try again.\n");
}

} while (choice != 0);

return 0;
}

