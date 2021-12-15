/*Find the last occurrence of a given character in the string, return its position. */
#include<stdio.h>

void string_last_occurrence(char *s, char ch) {
    int count = 0;
    int character_position = 0;
    while(*s != '\0') {
        if(*s == ch) {
            count++;
            character_position = count;
        }
        else
            count++;
        s++;
    }
    if(character_position == 0)
        printf("Character %c not found in the string", ch);
    else
        printf("Character %c last occurred at location %d", ch, character_position);
}

int main(void) {
    char str[] = "Batman: The Dark Knight";
    char ch = 'a';
    string_last_occurrence(str, ch);
    return 0;
}
