/*
Take a integer as input and return integer made up of first digit, last digit alternatively.
Input: 123456
Output: 162534

Idea:
1) find the first digit and last digit of the number.
2) Build the number.
3) Remove the first digit and last digit from the original number.
4) Remaining number is passed to next recursive call.

Explanation:
--> firstlastAlternate(123456);
--------> getFirstDigit(123456) -----------> First Digit: 1
--------> getLastDigit(123456) ------------> Last Digit: 6
--------> buildNum(1, 6, 0) ---------------> new_number: 16
--------> removeFirstandLastDigit(123456) -> num: 2345
--------> firstlastAlternate(2345);
---------------------> getFirstDigit(2345) -----------> First Digit: 2
---------------------> getLastDigit(123456) ------------> Last Digit: 5
---------------------> buildNum(2, 5, 16) ---------------> new_number: 1625
---------------------> removeFirstandLastDigit(2345) -> num: 34
---------------------> firstlastAlternate(34);
----------------------------------> getFirstDigit(34) -----------> First Digit: 3
----------------------------------> getLastDigit(34) ------------> Last Digit: 4
----------------------------------> buildNum(3, 4, 1625) ---------------> new_number: 162534
----------------------------------> removeFirstandLastDigit(34) -> num: 0
----------------------------------> firstlastAlternate(0);
----------------------------------> Terminate condition(True) : print(new_number): 162534
*/

#include<stdio.h>

/*Find first digit. */
int getFirstDigit(int num) {
    int firstDigit = num;
    while(firstDigit >= 10)
        firstDigit = firstDigit / 10;
    return firstDigit;
}

/*Find last digit. */
int getLastDigit(int num) {
    int lastDigit = num%10;
    return lastDigit;
}

/*Build the number. */
void buildNum(int firstDigit, int lastDigit, int *new_number) {
    *new_number = (*new_number) * 10 + firstDigit;
    *new_number = (*new_number) * 10 + lastDigit;
}

/*Remove the first and last digit from the original number. */
void removeFirstandLastDigit(int *p) {
    int y;
    *p = *p/10;
    y = *p;
    int count = 0;
    while(y >= 10) {
        y = y/10;
        count++;
    }
    int i;
    for(i=0; i<count; i++)
        y = y*10;
    *p = *p-y;
}

void firstlastAlternate(int num) {
    /*new_number is our modified number. */
    static int new_number = 0;

    /*Termination condition. */
    if(num == 0) {
        printf("\n Modified number is: %d", new_number);
        return 0;
    }
    /*If num is not 0 and num is >= 10. When num is not single digit. */
    else if(num >= 10){
        int firstDigit, lastDigit, count;
        firstDigit = getFirstDigit(num);
        lastDigit = getLastDigit(num);
        buildNum(firstDigit, lastDigit, &new_number);
        removeFirstandLastDigit(&num);
        firstlastAlternate(num);
    }
    /*If num is not 0 and num is <= 10. When num is single digit. */
    else {
        int firstDigit = getFirstDigit(num);
        /*
        When num is only a single digit number, then first digit and the last digit are same. So we use only first digit and modify the number. Otherwise it will create repeat.
        */
        new_number = new_number * 10 + firstDigit;
        printf("\n Modified number is: %d", new_number);
        return 0;
    }
}

int main(void) {
    int num;
    printf("\n Enter any number: ");
    scanf("%d", &num);
    firstlastAlternate(num);
    return 0;
}
