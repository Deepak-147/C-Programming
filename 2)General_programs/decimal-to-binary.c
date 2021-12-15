#include<stdio.h>

void binaryToDecimal(int n){
    int decimal[10];
    int sum = 0;
    int base = 1;//2^0 = 1
    while(n > 0){
        int last_digit = n%10;
        sum = sum + last_digit*base;
        n = n/10;
        base = base * 2;
    }
    printf("%d", sum);
}

int main(void) {
    int num = 11001;
    binaryToDecimal(num);
    return 0;
}
