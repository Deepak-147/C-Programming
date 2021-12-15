/*
 Find first and last digit of a number.

 Input: 123456
 Output: First = 1
         Last = 6
*/
#include<stdio.h>
int main(void) {
    int num, firstDigit, lastDigit;
    printf("\n Enter any number: ");
    scanf("%d", &num);

     /*Find Last digit. */
    lastDigit = num % 10;

    /*
    Find First Digit.
    Remove last digit from number till only one digit is left.
    */
    firstDigit = num;
    while(firstDigit >= 10) {
        firstDigit = firstDigit / 10;
    }

    printf("\n First digit = %d\n", firstDigit);
    printf("\n Last digit = %d\n", lastDigit);
    return 0;
}
