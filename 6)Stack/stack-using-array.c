#include<stdio.h>
#include<stdlib.h>

struct stack {
    int top;
    int capacity;
    int *array;
};

typedef struct stack STACK;

STACK* createStack(int capacity) {
    STACK *stack = (STACK *) malloc(sizeof(STACK));
    if(!stack)
        return NULL;
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (int *) malloc(stack->capacity * sizeof(int));
    if(!stack->array)
        return NULL;
    return stack;
}

int isFull(STACK *stack) {
    //return(stack->top == (stack->capacity)- 1);
    if(stack->top == (stack->capacity)- 1)
        return 1;
    else
        return 0;
}

int isEmpty(STACK *stack) {
    //return(stack->top == -1);
    if(stack->top == -1)
        return 1;
    else
        return 0;
}

void push(STACK *stack, int data) {
    if(isFull(stack))
        return;
    stack->top = stack->top + 1;
    stack->array[stack->top] = data;
    printf("\n\nPushed element: %d ", stack->array[stack->top]);
}

int pop(STACK *stack) {
    if(isEmpty(stack))
        return;
    int remove = stack->array[stack->top];
    stack->top = stack->top - 1;
    return remove;
}

int main(void) {

    STACK *stack = createStack(20);
    push(stack, 3);
    push(stack, 56);
    push(stack, 12);
    push(stack, 93);
    int removed = pop(stack);
    printf("\n\nPopped: %d", removed);
    return 0;
}