/*
Method 2: Log based Solution

Count number of digits in a number.

Input: 123456
Output: 6
*/

#include<math.h>
#include<stdio.h>

int countDigit(int n) {
    return ceil(log10(n));
}

int main(void) {
    int num;
    printf("\n Enter the number: ");
    scanf("%d", &num);
    printf("\n Number of digits : %d", countDigit(num));
    return 0;
}
