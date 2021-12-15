/*Factorial: Recursive version */
#include<stdio.h>
int factorial(int n) {
    if(n == 0)
        return 1;
    return n*factorial(n-1);
}

int main(void) {
    int num = 7;
    printf("\n\nThe factorial of %d is: %d", num, factorial(num));
    return 0;
}

