#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <ctype.h>



#define MAX_SIZE 100



struct Stack {

    int top;

    char items[MAX_SIZE];

};



void push(struct Stack* stack, char *item) {

    if (stack->top == MAX_SIZE - 1) {

        printf("Stack Overflow\n");

        return;

    }

    stack->items[++stack->top] = *item;

}



char pop(struct Stack* stack) {

    if (stack->top == -1) {

        printf("Stack Underflow\n");

        return -1;

    }

    return stack->items[stack->top--];

}



int isOperator(char symbol) {

    if (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/')

        return 1;

    return 0;

}



void postfixToInfix(char postfix[]) {

    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));

    stack->top = -1;

    int length = strlen(postfix);

    char operand1[50], operand2[50], operator3[50], *result[100];

    for (int i = 0; i < length; i++) {

        if (isalpha(postfix[i]) || isdigit(postfix[i])) {

            char temp[2];

            temp[0] = postfix[i];

            temp[1] = '\0';

            push(stack, temp[0]);

        } else if (isOperator(postfix[i])) {

            operand2[0] = pop(stack);

            operand1[0] = pop(stack);

            //operand2[1] = ')';

            operand2[1] = operand1[1] = '\0';

            operator3[0] = postfix[i];

            operator3[1] = '\0';



            strcpy(result, "(");

            strcat(result, operand1);

            strcat(result, operator3);

            strcat(result, operand2);

            strcat(result, ")");

            push(stack, *result);

        }

    }

    printf("Infix Expression: ");

    for (int i = 0; i < strlen(result); i++) {

        printf("%c", result[i]);

    }

}



int main() {

    char postfix[MAX_SIZE];

    printf("Enter a postfix expression: ");

    fgets(postfix, MAX_SIZE, stdin);

    postfixToInfix(postfix);

    return 0;

}
