#include <stdio.h>

int stack[50],top=-1;

void push(int item){
    top++;
    stack[top]=item;}

int pop(){
    int item = stack[top];
    top--;
    return item;}

void convert(int decimal,int base){
    while(decimal>0){
        int remainder=decimal%base;
        push(remainder);
        decimal/=base;}
    while(top!=-1){
        int digit=pop();
        printf("%d",digit);}
}

int main(){
    int decimal,base;
    printf("Enter decimal: ");
    scanf("%d",&decimal);
    printf("Enter a base: ");
    scanf("%d",&base);
    printf("%d converted to base %d is: ",decimal,base);
    convert(decimal,base);
    return 0;
}
