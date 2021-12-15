/*
A true palindrome is a sing which considers only alphabets and not any other characters(like digits or special characters), in determining sing is palindrome or not.
Input: MAD123DAM
Output: YES
Explanation:
Consider only MADDAM and no any other character other than alphabet in the sing. MADDAM is a palindrome and hence the output is YES.
Simply if we reverse it like MAD321DAM and compare it with MAD123DAM then it is not palindrome. A true palindrome ignores characters other than alphabet.
*/
#include<stdio.h>
void true_palindrome(char s[]) {
    int first_index = 0;
    int last_index = strlen(s) - 1;
    while(last_index > first_index) {
        if( ((s[first_index] >= 'a' && s[first_index] <='z') || (s[first_index] >= 'A' && s[first_index] <='Z')) && ((s[last_index] >= 'a' && s[last_index] <='z') || (s[last_index] >= 'a' && s[last_index] <='z')) ) {
            if(s[first_index] != s[last_index]) {
                printf("%s is not palindrome", s);
                return;
            }
        }
        first_index++;
        last_index--;
    }
    printf("%s is palindrome", s);
}
int main(void) {
    char s[] = "MAD123DAM";
    true_palindrome(s);
    return 0;
}
