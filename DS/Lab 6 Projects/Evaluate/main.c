#include <stdio.h>
#include <stdlib.h>
#define max 50
int stack[max],top=-1;

int IsOperator(char);
int IsOperand(char);
void push(int);
int pop();

int main(){
char prefix[50];
printf("Enter prefix expression ");
scanf("%s",&prefix);
strrev(prefix);
for(int i=0;prefix[i]!='\0';i++){
    if(IsOperand(prefix[i])){
        push(prefix[i]-'0');}
    if(IsOperator(prefix[i])){
        char a=prefix[i];
        int result=0;
        switch(a){
            case '+':
                result=pop()+pop();
                push(result);
                break;
            case '-':
                result=pop()-pop();
                push(result);
                break;
            case '*':
                result=pop()*pop();
                push(result);
                break;
            case '/':
                result=pop()/pop();
                push(result);
                break;}}
    }

printf("The result is %d",pop());
}

int pop(){
int c=stack[top];
top--;
return c;}

void push(int a){
top++;
stack[top]=a;}

int IsOperator(char c){
    if(c== '+'||c=='-'||c=='*'||c=='/'||c=='^') return 1;
    else return 0;}

int IsOperand(char c){
    if((c>='A'&&c<= 'Z')||(c>='a'&&c<='z')||(c>='0'&&c<='9')) return 1;
    else return 0;}




