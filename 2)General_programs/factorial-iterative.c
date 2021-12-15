/*Factorial: Iterative version */
#include<stdio.h>
int factorial(int n) {
    int i, res = 1;
    for(i = 2; i <= n; i++)
        res = res * i;
    return res;
}

int main(void) {
    int num = 7;
    printf("\n\nThe factorial of %d is: %d", num, factorial(num));
    return 0;
}
