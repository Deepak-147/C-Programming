/*
Count number of digits in a number.

Input: 123456
Output: 6
*/

#include<stdio.h>

int countDigit(int n) {
    int count = 0;
    while(n != 0) {
        n = n/10;
        count++;
    }
    return count;
}

int main(void) {
    int num;
    printf("\n Enter the number: ");
    scanf("%d", &num);
    printf("\n Number of digits : %d", countDigit(num));
    return 0;
}

