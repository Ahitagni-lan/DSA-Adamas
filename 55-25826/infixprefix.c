#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

// Stack definition
char stack[MAX];
int top = -1;

// Stack operations
void push(char item) {
    if (top >= MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = item;
}

char pop() {
    if (top < 0) {
        return '\0';
    }
    return stack[top--];
}

char peek() {
    if (top < 0) return '\0';
    return stack[top];
}

// Function to return precedence of operators
int precedence(char symbol) {
    switch (symbol) {
        case '^':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0;
    }
}

// Function to check if operator is right-associative (like '^')
int isRightAssociative(char symbol) {
    return symbol == '^';
}

// Function to convert Infix to Postfix
void infixToPostfix(char infix[], char postfix[]) {
    int i = 0, j = 0;
    char symbol, popped;

    while ((symbol = infix[i++]) != '\0') {
        // Ignore spaces and newlines
        if (symbol == ' ' || symbol == '\t' || symbol == '\n') {
            continue;
        }

        // If operand (letter or digit), append directly to output
        if (isalnum(symbol)) {
            postfix[j++] = symbol;
        }
        // If left parenthesis, push to stack
        else if (symbol == '(') {
            push(symbol);
        }
        // If right parenthesis, pop until matching '(' is found
        else if (symbol == ')') {
            while (top != -1 && peek() != '(') {
                postfix[j++] = pop();
            }
            pop(); // Remove '(' from stack
        }
        // If operator
        else {
            while (top != -1 && peek() != '(' &&
                   (precedence(peek()) > precedence(symbol) ||
                   (precedence(peek()) == precedence(symbol) && !isRightAssociative(symbol)))) {
                postfix[j++] = pop();
            }
            push(symbol);
        }
    }

    // Pop any remaining operators in the stack
    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0'; // Null-terminate string
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter an Infix expression (e.g., A+B*(C-D)): ");
    if (fgets(infix, sizeof(infix), stdin) != NULL) {
        infixToPostfix(infix, postfix);
        printf("Postfix Expression: %s\n", postfix);
    }

    return 0;
}
