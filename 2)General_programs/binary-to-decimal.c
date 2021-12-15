#include<stdio.h>

void decimalToBinary(int n){
    int binary[10];
    int i = 0;
    while(n > 0){
        binary[i] = n%2;
        n = n/2;
        i++;
    }
    for(i = 0; i < 10; i++)
        printf("%d", binary[i]);
}

int main(void) {
    int num = 25;
    decimalToBinary(num);
    return 0;
}

