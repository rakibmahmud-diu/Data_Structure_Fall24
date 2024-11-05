#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


struct Node {
    char data;
    struct Node* next;
};


struct Node* createNode(char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Overflow\n");
        return newNode;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


void push(struct Node** top, char data) {
    struct Node* newNode = createNode(data);
    newNode->next = *top;
    *top = newNode;
}


int isEmpty(struct Node* top) {
    return top == NULL;
}


char pop(struct Node** top) {
    if (isEmpty(*top)) {
        printf("Stack underflow\n");
        return '\0';
    }
    struct Node* temp = *top;
    char popped = temp->data;
    *top = (*top)->next;
    free(temp);
    return popped;
}


char peek(struct Node* top) {
    if (isEmpty(top)) {
        return '\0';
    }
    return top->data;
}


int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}


int precedence(char op) {
    switch (op) {
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}


void infixToPostfix(char* infix, char* postfix) {
    struct Node* stack = NULL;
    int k = 0; // Index for postfix output

    for (int i = 0; i < strlen(infix); i++) {
        char ch = infix[i];

        if (isalnum(ch)) {
            postfix[k++] = ch;
        }
        else if (ch == '(') {
            push(&stack, ch);
        }
        else if (ch == ')') {
            while (!isEmpty(stack) && peek(stack) != '(') {
                postfix[k++] = pop(&stack);
            }
            pop(&stack);
        }
        else if (isOperator(ch)) {
            while (!isEmpty(stack) && precedence(peek(stack)) >= precedence(ch)) {
                postfix[k++] = pop(&stack);
            }
            push(&stack, ch);
        }
    }

    while (!isEmpty(stack)) {
        postfix[k++] = pop(&stack);
    }
    postfix[k] = '\0';
}

int main() {
    char infix[100], postfix[100];

    printf("Enter infix expression: ");
    scanf("%[^\n]s", infix);

    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    return 0;
}
