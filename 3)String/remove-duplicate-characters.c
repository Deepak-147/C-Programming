#include<stdio.h>
#define ASCII_SIZE 256

void remove_duplicate_characters(char s[], int len) {
    char newString[ASCII_SIZE];
    int discard_index[len];
    int i, j;
    j = 0;
    for(i = 0; i < len; i++) {
        if(newString[s[i]] == s[i]){
            discard_index[j] = i;
            j++;
        }
        else
            newString[s[i]] = s[i];
    }
    int k = j;/*Actual indexes are till k elements of discard_index array */

    printf("\nGiven string is: %s\nAfter removing duplicate characters: ", s);
    for(i = 0; i < len; i++) {
        int flag = 0;
        for(j = 0; j < k; j++) {
            if(i != discard_index[j])
                continue;
            else {
                flag = 1;
                break;
            }
        }
        if(flag == 0)
            printf("%c", s[i]);
    }
}

int main(void) {
    char str[] = "MANHATTAN";
    int length = sizeof(str)/sizeof(str[0]);
    remove_duplicate_characters(str, length);
    return 0;
}
