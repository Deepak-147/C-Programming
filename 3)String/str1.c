/*Demonstrates basic string work around. */
#include<stdio.h>
int main(void) {
    /*
    //All are the same
    char str[] = "INDIA";
    char str[6] = "INDIA";
    char str[] = {'I', 'N', 'D', 'I', 'A', '\0'};
    char str[6] = {'I', 'N', 'D', 'I', 'A', '\0'};


    //When string is stored in read only memory, we cannot modify the string content
    char *str = "ANIMAL";
    *(str+1) = K;
    //This will not change the string to "AKIMAL"


    //Now string is stored in writable stack segment
    char str[] = "ANIMAL";
    *(str+1) = K;
    //This will change the string to "AKIMAL"


    //Now string is stored in writable heap segment
    char *str = (str *) malloc(sizeof(char) * 7);
    *(str+0) = 'A';
    *(str+1) = 'N';
    *(str+2) = 'I';
    *(str+3) = 'M';
    *(str+4) = 'A';
    *(str+5) = 'L';
    *(str+6) = '\0';

    *(str+1) = 'K';
    //This will change the string to "AKIMAL"

    */

    char str_1[] = "HELLO"; //Create an array using string constant, it reserves space for null-character automatically
    char str_2[6] = "HELLO"; //Store size-1 elements and 1 is reserved for '\0'
    char str_3[5] = "HELLO"; //Still valid and stores 5 elements but does not have space for '\0', so we can't use %s or functions like strcpy on S[] — using this call undefined behavior.
    char str_4[] = {'H', 'E', 'L', 'L', 'O', '\0'};
    char str_5[10] = "HELLO";

    printf("%s\n", str_1);
    printf("%s\n", str_2);
    printf("%s\n", str_3);//This gives unexpected behavior
    printf("%s\n", str_4);
    printf("%s\n\n", str_5);

    /*These  five statements give undefined behavior*/
    printf("%c\n", str_1);
    printf("%c\n", str_2);
    printf("%c\n", str_3);
    printf("%c\n", str_4);
    printf("%c\n", str_5);

    /*
    Empty character is not allowed
    char ch_2 = '';
    */
    char ch_1 = 'H';

    /*
    But Empty String is allowed
    */
    char str_6 = "";

    /*
    This is not allowed as initialization cannot be separated from declaration
    char str_7[3];
    str_7 = "abc";
    */


    /*
    This prints a string character by character.
    */
    char s[5] = "Hello";
    int i = 0;
    for(i = 0; i < sizeof s; i++)
        printf("%c", s[i]);
    printf("\n");

    return(0);
}

