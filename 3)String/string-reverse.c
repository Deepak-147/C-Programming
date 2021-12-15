#include<stdio.h>

void swap(char *x, char *y) {
    char temp = *x;
    *x = *y;
    *y = temp;
}

/*
Pointer version
When string length is provided as argument
*/

/*
void stringReverse(char *str, int len) {
    int first_index = 0;
    int last_index = len - 2;
    while(last_index > first_index) {
        swap(str+first_index, str+last_index);
        first_index++;
        last_index--;
    }
    printf("Reversed string is: %s", str);
}
*/


/*
Array version
When string length is provided as argument
*/

/*
void stringReverse(char str[], int len) {
    int first_index = 0;
    int last_index = len - 2;
    while(last_index > first_index) {
        swap(&str[first_index], &str[last_index]);
        first_index++;
        last_index--;
    }
    printf("Reversed string is: %s", str);
}


/*
Pointer Version
When string length is not provided
*/

void strRev(char *s) {
    /*
    After pointer operations we have to print the string, this will help us in printing the string.
    Since s will change.
    */
    char *startofString = s;

    /*points at first position. */
    char *firstposition = s;

    /*Move s till the end of the string. */
    while(*s)
        s++;

    /*Make the s one step back. To make it point at last position. */
    s--;

    /*points at last position. */
    char* lastposition = s;

    while(lastposition > firstposition) {
        swap(firstposition, lastposition);
        firstposition++;
        lastposition--;
    }
    printf("\nReversed string is: %s", startofString);
}

int main(void) {
    char str[] = "Dallas";
    //int length = sizeof(str) / sizeof(str[0]);
    //stringReverse(str, length);
    strRev(str);
    return 0;
}
