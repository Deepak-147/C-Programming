#include<stdio.h>
int main(void) {
    char p[] = "GATE2011";

    printf("\n\n%d", p);          /*address of first element = address of G*/

    printf("\n\n%d", p+5);        /*address of 5 elements after the first element = address of 0*/

    printf("\n\n%d", *p);         /*ASCII of G = 71*/

    printf("\n\n%d", *p+5);       /*ASCII of G+5 = 76*/

    printf("\n\n%d", *(p+5));     /*ASCII of (p+5) = ASCII of 0*/


    printf("\n\n%s", p);          /*GATE2011*/

    printf("\n\n%s", p+5);        /*011*/

    //printf("\n\n%s", *p);         /*Error*/

    //printf("\n\n%s", *p+5);       /*Error*/

    //printf("\n\n%s", *(p+5));     /*Error*/


    printf("\n\n%c", p);          /*unknown character*/

    printf("\n\n%c", p+5);        /*unknown character*/

    printf("\n\n%c", *p);         /*G*/

    printf("\n\n%c", *p+5);       /*L*/

    printf("\n\n%c", *(p+5));     /*0*/

    return 0;
}
