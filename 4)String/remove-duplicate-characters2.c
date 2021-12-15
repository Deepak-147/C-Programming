/*Remove duplicate characters from the string.
INPUT: MANHATTAN
OUTPUT: MANHT
*/
#include<stdio.h>
#define ASCII_SIZE 256

char* remove_duplicate_characters(char s[], int len) {
    char newString[ASCII_SIZE];

    /*
    Here can't just make char finalString[len] and return it. As it is created with automatic storage class and references
    to it will become invalid once it leaves its declaring scope, i.e., when the function returns. So dynamically allocated the memory inside the function
    */
    char *finalString = malloc(len);
    if(!finalString)
        return NULL;
    int i;
    int j = 0;
    /*For each character encountered, check if it is present in newString.
    If it is present, then it means it is repeated and we do not add it into finalString. Otherwise we add it.
    */
    for(i = 0; i < len; i++) {
        /*If character is present(meaning it is repeated) ignore it(means continue with next iteration), otherwise we add it to finalString. */
        if(newString[s[i]] == s[i])
            continue;
        /*character encountered for first time, add it to the finalString*/
        else {
            finalString[j] = s[i];
            newString[s[i]] = s[i];
            j++;
        }
    }
    return finalString;
}

int main(void) {
    char str[] = "MANHATTAN";
    int length = sizeof(str)/sizeof(str[0]);
    char *nonduplicated = remove_duplicate_characters(str, length);
    if(nonduplicated) {
        printf("%s", nonduplicated);
        free(nonduplicated);
    }
    return 0;
}



