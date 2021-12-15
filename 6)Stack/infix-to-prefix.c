/*
1) Reverse the infix expression i.e A+B*C will become C*B+A. Note while reversing each '(' will become ')' and each ')' becomes '('.
2) Obtain the postfix expression of the modified expression i.e CB*A+.
3) Reverse the postfix expression. Hence in our example prefix is +A*BC.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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
    NODE *new_node = (NODE* ) malloc(sizeof(NODE));
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

/*Reverse the given expression without using string function */
void reverse(char **first) {
    char *last = *first;
    int length = 0;
    int count = 0;
    while(*last != '\0') {
        length++;
        last++;
    }
    last--;
    while(**first != '\0' && count < length/2) {
        /*Swap without using third variable */
        **first = **first + *last;
        *last = **first - *last;
        **first = **first - *last;
        first++;
        last--;
        count++;
    }
    first = first - (length)/2;
}

int infixToPrefix(char *infixexp) {
    NODE *top = NULL;
    char prefix[100];
    char *postfix_string;
    int i = 0, count = 0;

    /*Reverse the infix expression */
    reverse(&infixexp);

    /*Replace ( with ) and vice versa */
    while(*infixexp != '\0') {
        if(*infixexp == '(') {
            *infixexp = ')';
            infixexp++;
        }
        else if(*infixexp == ')') {
            *infixexp = '(';
            infixexp++;
        }
    }

    /*Infix to Postfix conversion */
    postfix_string = infixToPostfix(infixexp);

    /*Reverse the postfix */
    reverse(&postfix_string);
    printf("\n\nEquivalent Prefix expression is: %s", postfix_string);
}

char* infixToPostfix(char *infixexp) {
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
    }

    /*Pop all the remaining operators from the stack */
    while(!isEmpty(top))
        postfix[i++] = pop(&top);
    postfix[i++] = '\0';
    return postfix;
}

int main(void) {
    /*Declare an empty character stack */
    int i = 0;
    char expression[100];
    printf("\nInfix to Prefix conversion");
    printf("\n------------------------------");
    printf("\n\nEnter an Infix expression: ");
    char ch;
    while((ch = getchar())!= '\n')
        expression[i++] = ch;
    expression[i] = '\0';
    infixToPrefix(expression);
    return 0;
}

