/*
1) Scan the expression from left to right
2) If the scanned character is an operand, output it.
3) Else,
        3.1) If the precedence of the scanned operator is greater than the precedence of the operator in the stack(or the stack is empty), push it.
        3.2) Else, Pop the operator from the stack until the precedence of the scanned operator is less-equal to the precedence of the operator residing on the top of the stack. Push the scanned operator to the stack.
4) If the scanned character is an '(', push it to the stack.
5) If the scanned character is an ')', pop and output from the stack until an '(' is encountered.
6) Repeat steps 2-6 until infix expression is scanned.
7) Pop and output from the stack until it is not empty.
*/

#include<stdio.h>
#include<stdlib.h>

struct Node {
    char data;
    struct Node *next;
};
typedef struct Node NODE;

/*Checks whether the given character is operand */
int isOperand(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

void push(NODE **top_ref, char data) {
    NODE *new_node = (NODE *) malloc(sizeof(NODE));
    if(new_node == NULL) {
        printf("\n\nStack Overflow");
        exit(0);
    }
    new_node->data = data;
    new_node->next = (*top_ref);
    (*top_ref) = new_node;
}

char peek(NODE *top) {
    if(isEmpty(top))
        return 1;
    return top->data;
}

char pop(NODE **top_ref) {
    if(*top_ref == NULL) {
        printf("\n\nStack Underflow");
        exit(0);
    }
    NODE *temp = (*top_ref);
    (*top_ref) = (*top_ref)->next;
    char popped = temp->data;
    free(temp);
    return popped;
}

int isEmpty(NODE *top) {
    return (!top);
}

/*function to return precedence of a given operator, Higher returned value means higher precedence */
int precedence(char ch) {
    switch(ch) {
        case '+':
        case '-':
            return 1;

        case '*':
        case '/':
            return 2;

        case '^':
            return 3;
    }
    return -1;
}

int infixToPostfix(char *infixexp) {
    NODE *top = NULL;
    char postfix[100];
    int i = 0;
    while(*infixexp != '\0') {
        /* If the scanned character is an operand, add it to output */
        if(isOperand(*infixexp))
            postfix[i++] = *infixexp;

        /*If the scanned character is an '(', push it to the stack */
        else if(*infixexp == '(')
            push(&top, *infixexp);

        /*If the scanned character is an ')', pop and output from the stack until an '(' is encountered */
        else if(*infixexp == ')') {
            /*while top of stack is not '(' and the stack is not empty, continue popping top of stack to the output */
            while(peek(top) != '(' && !isEmpty(top))
                postfix[i++] = pop(&top);
            if(peek(top) != '(' && !isEmpty(top))
                return -1;
            else
                pop(&top);
        }
        /*an operator is encountered */
        else {
            /*while scanned operator has lower precedence than the top of stack and the stack is not empty, keep popping top of stack to the output */
            while(precedence(*infixexp) <= precedence(peek(top)) && !isEmpty(top))
                postfix[i++] = pop(&top);
            push(&top, *infixexp);
        }
        *infixexp++;
        //printf("\n%s", postfix);
    }

    /*Pop all the remaining operators from the stack */
    while(!isEmpty(top))
        postfix[i++] = pop(&top);
    postfix[i++] = '\0';
    printf("\n\nEquivalent Postfix expression is: %s", postfix);
}

int main(void) {
    /*Declare an empty character stack */
    int i = 0;
    char expression[100];
    printf("\nInfix to Postfix conversion");
    printf("\n------------------------------");
    printf("\n\nEnter an Infix expression: ");
    char ch;
    while((ch = getchar())!= '\n')
        expression[i++] = ch;
    expression[i] = '\0';
    infixToPostfix(expression);
    return 0;
}
