/*String Palindrome: Iterative version */
/*Example: DEED is palindrome, but DEEP is not. */
/*compare the first and the last characters. */
#include<stdio.h>
#include<string.h>

/*
Pointer version

void string_palindrome_iterative(char *s) {
    int first_index = 0;
    int last_index = strlen(s) - 1;
    while(last_index > first_index) {
        if(s[first_index++] != s[last_index--]) {
            printf("%s is not palindrome", s);
            return;
        }
    }
    printf("%s is palindrome", str);
}

*/

void string_palindrome_iterative(char str[]) {
    int first_index = 0;
    int last_index = strlen(str) - 1;
    while(last_index > first_index) {
        if(str[first_index++] != str[last_index--]) {
            printf("%s is not palindrome", str);
            return;
        }
    }
    printf("%s is palindrome", str);
}

int main(void) {
    char str[] = "MADAM";
    string_palindrome_iterative(str);
    return 0;
}
