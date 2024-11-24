#include <stdio.h>
#include <stdlib.h>


struct Node {
    char data;
    struct Node* next;
};


struct Node* createNode(char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
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
        return '\0';
    }
    struct Node* temp = *top;
    char popped = temp->data;
    *top = (*top)->next;
    free(temp);
    return popped;
}


int isBalanced(char* expression) {
    struct Node* stack = NULL;
    for (int i = 0; expression[i] != '\0'; i++) {
        char current = expression[i];

        if (current == '(') {
            push(&stack, current);
        }

        else if (current == ')') {
            if (isEmpty(stack)) {
                return 0;
            }
            pop(&stack);
        }
    }
    return isEmpty(stack);
}

int main() {
    char expression[100];

    printf("Enter an expression with parentheses: ");
    scanf("%s", expression);

    if (isBalanced(expression)) {
        printf("The expression is balanced.\n");
    } else {
        printf("The expression is not balanced.\n");
    }

    return 0;
}
