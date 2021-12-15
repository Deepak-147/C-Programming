/*
Take a integer as input and return integer made up of first digit, last digit alternatively.
Input: 123456
Output: 162534

Idea:
1) Count the number of digits in the number.
2) Build a character array from the number.
3) Build new number by taking first digit and last digit alternately.

Explanation:
-->firstlastAlternate(1090);
----->countDigits(1090) ------------> number_of_digits: 4
----->buildCharArray(1090, 4) ------> number[0]: 0
------------------------------------> number[1]: 9
------------------------------------> number[2]: 0
------------------------------------> number[3]: 1
------------------------------------> return pointer to number
----->buildNewNum(&number, 4)-------> new_number : 0
------------------------------------> new_number : 1
------------------------------------> new_number : 10
------------------------------------> new_number : 100
------------------------------------> new_number : 1009
------------------------------------>print(new_number) : 1009
*/

#include<stdio.h>
#include<stdlib.h>
int countDigits(int num) {
    int count = 0;
    while(num) {
        num = num/10;
        count++;
    }
    return count;
}
char* buildCharArray(int num, int number_of_digits) {
    /*
    Dynamic memory allocation for character array. Otherwise, if we create char number[number_of_digits] and return it,
    it will be created with automatic storage class and references to it will become invalid once it leaves its declaring scope.
    */
    char *number = malloc(number_of_digits);
    int i=0;
    while(num) {
         number[i]= num%10;
         num = num/10;
         i++;
    }
    return number;
}
void buildNewNum(char *number, int number_of_digits) {
    int new_number = 0;
    int i=0, j=number_of_digits-1;
    while(i<=j) {
        if(i == j) {
            new_number = new_number*10 + *(number+j);
            break;
        }
        new_number = new_number*10 + *(number+j);
        new_number = new_number*10 + *(number+i);
        i++;
        j--;
    }
    printf("\n Modified number is: %d", new_number);
    free(number);
}
void firstlastAlternate(int num) {
    int number_of_digits = countDigits(num);
    char *number = buildCharArray(num, number_of_digits);
    buildNewNum(number, number_of_digits);
}

int main(void) {
    int num;
    printf("\n Enter any number: ");
    scanf("%d", &num);
    firstlastAlternate(num);
    return 0;
}
