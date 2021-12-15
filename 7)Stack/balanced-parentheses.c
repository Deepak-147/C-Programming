#include<stdio.h>
#include<stdlib.h>

struct Node {
    char data;
    struct Node *next;
};
typedef struct Node NODE;

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

int main(void) {
    /*Declare an empty character stack */
    NODE *top = NULL;
    int i = 0;
    char expression[100];
    printf("Enter the expression to be tested: ");
    char ch;
    while((ch = getchar())!= '\n') {
        expression[i] = ch;
        i++;
    }
    expression[i] = '\0';
    i = 0;
    while(expression[i] != '\0') {
        /*If the expression[i] is a starting parenthesis then push it */
        if(expression[i] == '{' || expression[i] == '(' || expression[i] == '[') {
            push(&top, expression[i]);
            i++;
            continue;
        }

        /*If the expression[i] is a closing parenthesis then pop from stack and check if the popped parenthesis is a matching pair */
        if(expression[i] == '}' || expression[i] == ')' || expression[i] == ']') {
            char popped = pop(&top);
            if(!(popped == expression[i])) {
                printf("Not Balanced!");
                return 0;
            }
        }
        i++;
    }

    /*If stack is not empty then it means expression is not balanced*/
    if(top == NULL)
        printf("\n\nBalanced!");
    else
        printf("\n\nNot Balanced!");
}
