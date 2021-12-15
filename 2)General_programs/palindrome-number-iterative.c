/*Number Palindrome: Iterative version */
/*101 is palindrome */
/*Reverse the number and check with original number */

#include<stdio.h>
void number_palindrome_iterative(int number) {
    int num = number;
    int rem;
    int sum = 0;
    while(num) {
        rem = num%10;
        sum = sum*10 + rem;
        num = num/10;
    }
    if(sum == number)
        printf("\n\n%d is palindrome", number);
    else
        printf("\n\n%d is not palindrome", number);
}

int main(void) {
    int number = 101;
    number_palindrome_iterative(number);
    return 0;
}
