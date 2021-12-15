#include<stdio.h>
int main(void) {
    int a, b, c, x, y, z;
    for(a=0; a<5; a++) {
        for(b=8; b>2*a; b--)
            printf(" ");
    for(c=0; c<=a; c++) {
        printf("*");
        printf(" ");
    }
    printf("\n");
    }
    for(x=0; x<5; x++) {
        for(y=0; y<2*x; y++)
            printf(" ");
    for(z=5; z>x; z--) {
        printf("*");
        printf(" ");
    }
    printf("\n");
    }
    return 0;
}
