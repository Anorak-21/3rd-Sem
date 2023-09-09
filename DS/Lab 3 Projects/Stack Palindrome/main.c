#include <stdio.h>
#include <stdlib.h>
int top=-1,stack[50];



int main(){

int choice,item;

do {
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Peek\n");
    printf("4. Exit\n");

    printf("Enter your choice: ");
    scanf("%d",&choice);
    switch(choice) {
        case 1:
            printf("Enter the item to push: ");
            scanf("%d", &item);
            push(item);
            break;
        case 2:

            if (top==-1) {printf("No elements to pop \n");}
            else {printf("Popped item: %d\n",item);item=pop();}
            break;
        case 3:
            item=peek();
            if (item != -1)
            printf("Top item: %d\n", item);
            break;
        case 4:
            printf("Exiting...\n");
            choice=0;
            break;

        default:
            printf("Invalid choice, please try again.\n");
    }
} while(choice!=0);}

int peek(){
return stack[top];}

int pop(){
return stack[top--];}

void push(int c){
top++;
stack[top]=c;}
