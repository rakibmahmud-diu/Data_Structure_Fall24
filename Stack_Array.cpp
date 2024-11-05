#include <stdio.h>
#include <stdlib.h>


struct Stack {
    int top;
    int capacity;
    int* array;
};

struct Stack* createStack(int capacity)
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)calloc(capacity, sizeof(int));
    return stack;
}


int isFull(struct Stack* stack)
{
    return stack->top == stack->capacity - 1;
}


int isEmpty(struct Stack* stack)
{
    return stack->top == -1;
}


void push(struct Stack* stack, int item)
{
    if (isFull(stack)) {
        printf("Overflow\n");
        return;
    }
    stack->array[++stack->top] = item;
    //printf("%d pushed to stack\n", item);
}


int pop(struct Stack* stack)
{
    if (isEmpty(stack)) {
        printf("Underflow\n");
        return -1;
    }
    return stack->array[stack->top--];
}


int peek(struct Stack* stack)
{
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->array[stack->top];
}


void display(struct Stack* stack)
{
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
    }
    else {
        for (int i = stack->top; i >= 0; i--) {
            printf("%d\n", stack->array[i]);
        }
    }
}


int main()
{
    struct Stack* stk = createStack(100);

    push(stk, 1);
    display(stk);
    push(stk, 2);
    display(stk);
    push(stk, 3);
    display(stk);

    printf("%d popped from stack\n", pop(stk));
    printf("Top element is %d\n", peek(stk));
    pop(stk); pop(stk); pop(stk);
    printf("Elements present in stack:\n");
    display(stk);

    return 0;
}
