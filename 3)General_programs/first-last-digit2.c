/*
 Method2: Log based solution.
 Find first and last digit of a number.

 Input: 123456
 Output: First = 1
         Last = 6
*/
#include<stdio.h>
#include<math.h>
int main(void) {
    int num, firstDigit, lastDigit, numberOfDigits;
    printf("\n Enter any number: ");
    scanf("%d", &num);

    /*Find last digit. */
    lastDigit = num % 10;

    /*Total number of digits - 1. */
    numberOfDigits = (int)log10(num);

    /*Find first digit. */
    firstDigit = (int)(num / pow(10, numberOfDigits));
    printf("\n First digit = %d\n", firstDigit);
    printf("\n Last digit = %d\n", lastDigit);
    return 0;
}
