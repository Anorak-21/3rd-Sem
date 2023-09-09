#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

char stack[MAX_SIZE][MAX_SIZE];
int top=-1;

void push(char element[]) {
        printf("%s",element);
        top++;
        strcpy(stack[top],element);}

const char *pop() {
    char c;
    strcpy(c,stack[top]);
    top--;
    return c;}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');}

void convert(char postfix[]) {
    char infix[100];
    char push1[100];
    int len = strlen(postfix);
    int infixIndex=0;
    for (int i=0;i<len;i++) {
        char token = postfix[i];

        if (!isOperator(token)) {
            push(token);}
        else {
            char operand1[100];
            strcpy(operand1,pop());
            char operand2[100];
            strcpy(operand2,pop());

            infix[infixIndex++] = '(';
            infix[infixIndex++] = operand2;
            infix[infixIndex++] = token;
            infix[infixIndex++] = operand1;
            infix[infixIndex++] = ')';
            infix[infixIndex] = '\0';
            push(infix);}
    }


}

int main() {
    char postfix[MAX_SIZE];
    char res[MAX_SIZE];
    printf("Enter a postfix expression: ");
    scanf("%s", postfix);

    convert(postfix);
    printf("Infix expression: %s\n", pop());

    return 0;
}
