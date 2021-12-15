#include<stdio.h>
#define ASCII_SIZE 256

void find_max_occuring_character(char s[], int len) {
    /*
    Array count keeps the count of the individual characters in the string. Initialize the array as 0.
    */
    int count[ASCII_SIZE] = {0};
    /*
    For each character encountered, we increment its previous count. How we will get to its previous count??.
    This is done by directly using its ASCII value to give same index all the time. Since there are 256 ASCII characters we took size of the array as 256.
    Ex: index [ASCII value of I] will be same for every I encountered.
    Thus if s = "INDIA", then count[s[0]] = count[ASCII value of I] = same every time I is encountered.
    */
    int i;
    for(i = 0; i < len; i++)
        count[s[i]]++;

    int max = 0;
    int max_index;
    for(i = 0; i < len; i++) {
        if(count[s[i]] > max) {
            max = count[s[i]];
            max_index = i;
        }
    }
    printf("\n\nGiven string is: %s \nMaximum Occurring character is: %c, and it occurred %d times ", s, s[max_index], max);
}

int main(void) {
    char str[] = "INDIA";
    int length = sizeof(str)/sizeof(str[0]);
    find_max_occuring_character(str, length);
    return 0;
}
