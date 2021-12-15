#include<stdio.h>
#define ASCII_SIZE 256
void second_most_occurring(char s[], int len) {
    int count[ASCII_SIZE] = {0};
    int i;
    for(i = 0; i < len-1; i++) {
        count[s[i]]++;
        printf("\n%d\n", count[s[i]]);
    }

    int first_max = 0;
    int second_max = 0;
    int second_max_position;
    for(i = 0; i < len-1; i++) {
        if(count[s[i]] > first_max) {
            second_max = first_max;
            second_max_position = i-1;
            first_max = count[s[i]];
        }
        else if(count[s[i]] > second_max && count[s[i]] != first_max) {
            second_max = count[s[i]];
            second_max_position = i;
        }
    }
    printf("\nThe second most occurring character is %c and it occurred %d times", s[second_max_position], second_max);
}

int main(void) {
    char str[] = "INSPIRATION";
    int length = sizeof(str)/sizeof(str[0]);
    second_most_occurring(str, length);
    return 0;
}
