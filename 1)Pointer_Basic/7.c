#include<stdio.h>
int main(void) {
    char *a[] = {"India", "Australia", "Germany", "Brazil", "USA", "China"};
    char *b[] = {a+3, a+2, a+1, a+5, a, a+4};
    char ***c = b;

    *c++;

    printf("\n\n%s", *++*++c);
    printf("\n\n%s", ++**(c+2));
    printf("\n\n%s", ++**c+2);
    return 0;
}
