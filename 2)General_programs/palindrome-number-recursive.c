/*Number Palindrome: Recursive version */
/*101 is palindrome */
/*Reverse the number and check with original number */

#include<stdio.h>
int number_palindrome_recursive(int number) {
    static int sum = 0;
    int rem;
    if(number) {
        rem = number%10;
        sum = sum*10 + rem;
        number = number/10;
        number_palindrome_recursive(number);
    }
    else
        return sum;
    return sum;
}

int main(void) {
    int number = 101;
    int result = number_palindrome_recursive(number);
    if(result == number)
        printf("\n\n%d is palindrome", number);
    else
        printf("\n\n%d is not palindrome", number);
    return 0;
}
