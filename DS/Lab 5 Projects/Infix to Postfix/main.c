#include<stdio.h>
#include<string.h>
#define MAX_SIZE 100

int IsOperator(char);
int IsOperand(char);
int eqlOrhigher(char, char);
void convert(char[],char[]);

int main(){
    char infix[MAX_SIZE],postfix[MAX_SIZE];
    int ch;
    do{
        printf("Enter an infix expression: ");
        scanf("%s", infix);
        convert(infix,postfix);
        printf("\nYour Infix expression is: %s", infix);
        printf("\nPostfix expression is: %s", postfix);
        printf("\nDo you want to enter infix expression (1/0)? ");
        scanf("%d",&ch);
    } while(ch==1);}

int IsOperator(char c){
    if(c== '+'||c=='-'||c=='*'||c=='/'||c=='^') return 1;
    else return 0;}

int IsOperand(char c){
    if((c>='A'&&c<= 'Z')||(c>='a'&&c<='z')||(c>='0'&&c<='9')) return 1;
    else return 0;}

int precedence(char op){
    if(op=='+'||op=='-') return 1;
    if(op=='*'||op=='/') return 2;
    if(op=='^') return 3;
    else return 0;}

int eqlOrhigher(char op1,char op2){
    int p1=precedence(op1);
    int p2=precedence(op2);
    if (p1==p2){
        if(op1=='^') return 0;
        else return 1;}
    if(p1>p2) return 1;
    else return 0;}

void convert(char infix[],char postfix[]){
    char ch,S[MAX_SIZE];
    int i=0,p=0,top=-1;
    S[++top] = '(';
    strcat(infix,")");
    for(i=0;infix[i]!='\0';i++){
        ch=infix[i];
        if(ch==' ') continue;
        else if(ch=='(') S[++top]=ch;
        else if (IsOperand(ch)) {postfix[p++]=ch;}
        else if (IsOperator(ch)) {
            while(top!=-1&&eqlOrhigher(S[top],ch)){
                postfix[p++]=S[top--];}
            S[++top]=ch;}
        else if (ch==')'){
            while(top!=-1&&S[top]!='(') {
                postfix[p++]=S[top--];}
            top--;}}
    postfix[p] = '\0';
}
