#include <stdio.h>
#include <stdlib.h>

#define max_size 5
int queue[max_size],front=-1,rear=-1;

int isEmpty(){
if(front==-1&&rear==-1) return 1;
else return 0;}

int isFull(){
if((rear+1)%max_size==front) return 1;
else return 0;}

void enqueue(int data){
if(isEmpty()) {
        front=rear=0;
        queue[rear]=data;}
else if(isFull()) {
        printf("The Queue is full");}
else {
        rear=rear%max_size+1;
        queue[rear]=data;}}

int dequeue(){
if(isEmpty()) {printf("The Queue is empty");}
int c=queue[front];
    if(front==rear) {front=rear=-1;}
    else {front++;}
    return c;}

void display(){
int i;
if(isEmpty()){
    printf("The Queue is empty");}
else{
        while(i<rear)
        {
            printf("%d\n", queue[i]);
            i=(i+1)%max_size;
        }
    printf("%d", queue[i]);
    }
}

int main() {

int c,choice,item;
do {
    printf("\n1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Display\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d",&choice);
    switch(choice) {
        case 1:
            printf("Enter the item to queue: ");
            scanf("%d", &item);
            enqueue(item);
            break;
        case 2:
            c=dequeue();
            printf("The element is %d",c);
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting...\n");
            choice=0;
            break;
        default:
            printf("Invalid choice, please try again.\n");}
} while(choice!=0);






}

