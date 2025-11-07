#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    if (top == MAX - 1)
        printf("Stack Overflow!\n");
    else
        stack[++top] = c;
}

char pop() {
    if (top == -1)
        return '\0';
    else
        return stack[top--];
}

int isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}

int isBalanced(char *exp) {
    for (int i = 0; i < strlen(exp); i++) {
        char c = exp[i];
        if (c == '(' || c == '[' || c == '{')
            push(c);
        else if (c == ')' || c == ']' || c == '}') {
            if (top == -1 || !isMatchingPair(pop(), c))
                return 0;
        }
    }
    return top == -1;
}

int main() {
    char exp[MAX];
    printf("Enter an expression: ");
    scanf("%s", exp);

    if (isBalanced(exp))
        printf("Parentheses are balanced.\n");
    else
        printf("Parentheses are NOT balanced.\n");

    return 0;
}
