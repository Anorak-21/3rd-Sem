#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_SIZE 100
#define STR_SIZE 150

char S[MAX_SIZE][STR_SIZE];
int top = -1;

int IsOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

void push(char str[]) {
    top++;
    strcpy(S[top], str);
}

void pop(char str[]) {
    strcpy(str, S[top]);
    top--;
}

void evaluate(char prefix[]) {

    top = -1;
    for (int i = 0; prefix[i] != '\0'; i++) {
        if (prefix[i] == ' ')
            continue;
        else if (isdigit(prefix[i])) {
            char num[10];
            int j = 0;
            while (isdigit(prefix[i])) {
                num[j++] = prefix[i++];
            }
            num[j] = '\0';
            i--;
            push(num);
        } else if (isalpha(prefix[i])) {
            char alpha[2] = {prefix[i], '\0'};
            push(alpha);
        } else if (IsOperator(prefix[i])) {
            char operand2[STR_SIZE], operand1[STR_SIZE], result[STR_SIZE];
            pop(operand2);
            pop(operand1);
            sprintf(result, "(%s%c%s)", operand1, prefix[i], operand2);

            push(result);
        }
    }
}

int main() {
    char prefix_expression[MAX_SIZE];
    int ch;
    do {
        printf("Enter a prefix expression: ");
        scanf("%[^\n]", prefix_expression);
        getchar();
        strrev(prefix_expression);
        evaluate(prefix_expression);
        printf("Infix = %s\n", S[top]);
        printf("Do you want to enter a prefix expression (1/0)? ");
        scanf("%d", &ch);
        getchar();
    } while (ch == 1);
    return 0;
}
