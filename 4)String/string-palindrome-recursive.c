/*String Palindrome: Recursive version */
/*Example: DEED is palindrome, but DEEP is not. */
/*compare the first and the last characters. */

#include<stdio.h>
#include<string.h>

int string_palindrome_recursive(char str[], int first_index, int last_index) {
    if(last_index > first_index) {

        /*Now MADAM is palindrome, but MADAm is not. To take care of the cases also then take this condition:

        if(str[first_index] == str[last_index] || str[first_index] + 32 == str[last_index] || str[first_index] == str[last_index] +32)

        */
        if(str[first_index] == str[last_index]) {
            return (string_palindrome_recursive(str, first_index+1, last_index-1)); /*Direct return from the function, on termination of the recursion it returns value and skips the rest of the code.  */
        }
        else
            return 0;
    }
    return 1;
}
int main(void) {
    char str[] = "MADAM";
    int first_index = 0;
    int last_index = strlen(str) - 1;
    int result = string_palindrome_recursive(str, first_index, last_index);
    if(result)
        printf("%s is palindrome", str);
    else
        printf("%s is not palindrome", str );
    return 0;
}
