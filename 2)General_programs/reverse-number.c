#include<stdio.h>

void reverse(int num) {
    int rem;
    int sum = 0;
    while(num > 0) {
        rem = num%10;
        sum = sum*10 + rem;
        num = num/10;
    }
    printf("\n\n Reverse of the number is: %d", sum);
}

int main(void) {
    int num = 1234;
    reverse(num);
    return 0;
}
