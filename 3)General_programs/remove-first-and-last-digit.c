/*
Remove first and last digit from a number.
Input: 123456
Output: 2345

Idea:
Take the number. Remove its last digit.
subtract 10^(number of digits-1) from the number.

1) 123456 / 10 = 12345
2) count number of digits-1. Number of digits in 12345 is 5, and decreasing by 1 gives us 4.
3) Build 10^(number of digits-1). Here it is builds 10^4.
4) 12345-10000 = 2345.

*/

#include<stdio.h>
void removeFirstandLastDigit(int x) {
    int y;
    x = x/10;
    y = x;
    int count = 0;
    while(y >= 10) {
        y = y/10;
        count++;
    }
    int i;
    for(i=0; i<count; i++)
        y = y*10;
    x = x-y;
    printf("\n After removing first and last digit: %d", x);
}
int main(void) {
    int num;
    printf("\n Enter any number: ");
    scanf("%d", &num);
    removeFirstandLastDigit(num);
    return 0;
}
