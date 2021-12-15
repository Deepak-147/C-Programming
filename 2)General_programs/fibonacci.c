/*
Fn of Fibonacci numbers is defined by the recurrence relation:
Fn = Fn-1 + Fn-2
*/
#include<stdio.h>
int fibonacci(int num) {
    if(num <= 1)
        return num;
    return fibonacci(num-1) + fibonacci(num-2);
}

int main(void) {
    int num;
    printf("Enter the position: ");
    scanf("%d", &num);
    printf("Fibonacci number at position %d is: %d", num, fibonacci(num));
    return 0;
}
