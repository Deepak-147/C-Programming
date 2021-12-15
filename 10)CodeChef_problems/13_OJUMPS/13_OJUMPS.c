#include<stdio.h>
int main(void)
{
    long int a, rem;
    scanf("%ld", &a);
    rem = a%6;
    if((rem == 0) || (rem == 1) || (rem == 3))
        printf("yes\n");
    else
        printf("no\n");
    return(0);
}
