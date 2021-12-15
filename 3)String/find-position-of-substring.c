/*
Find the position of the given substring in the string.
Return an array containing these index values.

Input: Text[] = "ILOVEINDIA"
       Pat[] = "INDIA"
Output: INDIA found at index:
        6

Input: Text[] = "AABAACAADAABAABA"
       Pat[] = "AABA"
Output: AABA found at index:
        0
        9
        12
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int* find_position_of_substring(char Text[], char Pat[]) {
    int lengthOfText = strlen(Text);
    int lengthOfPat = strlen(Pat);
    if(lengthOfText < lengthOfPat) {
        printf("\n Given Pattern exceeds the length of the Text. Hence cannot be found. ");
        return 0;
    }
    int i, j = 0, k = 0, count = 0, flag = 0;
    int position[10];
    for(i = 0; i < lengthOfText; i++) {
        if(Text[i] == Pat[j] && j < lengthOfPat) {
            j++;
            /*If complete pattern is found. */
            if(j == lengthOfPat) {
                /*Set the flag, this will help in determining whether the pattern is found or not. */
                flag = 1;
                /*
                There can be possibility of start of new substring within the substring.
                Ex: if Text is ABABABA and Pat is ABAB.
                First substring starts at position 0 till position 3. But next substring could start from any position between 0 and 3.
                As in this case second substring starts at position 2 till position 5. To take this into account we decrement i by (lengthOfPat-1).
                */
                i = i - (lengthOfPat - 1);
                j = 0;
                count++;
                position[k++] = i;
            }
        }
        /*If there is mismatch, we have to bring back i to appropriate place. */
        else {
            /*
            If there is mismatch at position j in Pat, we need to shift i to j positions back.
            So in next iteration i increments and starts at position i-j+1 in Text.
            */
            i = i - j;
            j = 0;
        }
    }

    /*If flag was not set, it means that pattern is not found. And we return to main(). */
    if(flag == 0) {
        printf("\n Pattern not found. ");
        exit(0);
    }
    /*
    Dynamically allocate an array of size "count+1" integers. Copy index values from the position array to this new array.
    Store a Sentinal value like -1 at the last position. This will help in iterating the pointer in the main(). Otherwise, how we will find the size of the array.
    As we cannot get the size of the array with only the pointer to an array.
    */
    int *indexes = (int *) malloc(sizeof(int) * (count+1));
    /*Makes sure malloc was successful. */
    if(!indexes) {
        printf("\n Memory Insufficient. ");
        exit(0);
    }

    i = 0;
    /*copy the values to this new array indexes. */
    while(count) {
        *(indexes + i) = position[i];
        i++;
        count--;
    }

    /*Assign a Sentinal value to the last index. */
    *(indexes + i) = -1;
    return indexes;
}

int main(void) {
    char Text[] = "AABAACAADAABAABA";
    char Pat[] = "AABA";

    int *indexes = find_position_of_substring(Text, Pat);
    /*
    With just the pointer to the array, we cannot find the size of the array and hence cannot iterate and print the values.
    The checking for NULL trick only works for NULL terminated strings. But for a numeric array we will have to pass in the size too.
    To avoid passing the size we added a Sentinal value to the end of the array. Now this will help in iterating the array and printing the indexes.
    */
    printf("\n %s occurred at indexes: ", Pat);
    while(*indexes != -1) {
        printf("\n %d", *indexes);
        indexes++;
    }
    return 0;
}
