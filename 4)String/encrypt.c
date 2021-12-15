/*
Encrypt a string.
Encryption technique: Replace a character by the next letter in the alphabet.
Assuming z or Z loop to that start to become a or A respectively.

Input: INDIA
Output: JOEJB

*/

#include<stdio.h>

void encryptMe(char *notEncrypted) {
    while(*notEncrypted != '\0') {
        /*If it is z or Z subtract 25 to loop to the start. */
        if(*notEncrypted == 'z' || *notEncrypted == 'Z')
            *notEncrypted = *notEncrypted - 25;
        /*If it is a space, do nothing. */
        else if(*notEncrypted == ' ');
        /*Otherwise, increment by 1. */
        else
            *notEncrypted = *notEncrypted + 1;
        notEncrypted++;
    }
}

int main(void) {
    int length;
    printf("\n Enter the length of the string to be encrypted: ");
    scanf("%d", &length);
    char notEncrypted[length];
    /*Flush the input buffer otherwise the newline character from previous scanf becomes input to gets()*/
    fflush(stdin);
    printf("\n Enter the string to encrypt: ");
    gets(notEncrypted);

    encryptMe(notEncrypted);
    printf("\n Encrypted string is: %s", notEncrypted);
    return 0;
}
