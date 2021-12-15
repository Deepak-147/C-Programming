/*Count the occurrence of a given substring in the string. Count overlapping strings also.

Input: Text[] = "ILOVEINDIA"
       Pat[] = "INDIA"
Output: 1 time

Input: Text[] = "AABAACAADAABAABA"
       Pat[] = "AABA"
Output: 3 times

*/

#include<stdio.h>
#include<string.h>
void count_occurrence_of_subsrting(char Text[], char Pat[]) {
    int lengthOfText = strlen(Text);
    int lengthOfPat = strlen(Pat);
    if(lengthOfText < lengthOfPat) {
        printf("\n Given Pattern exceeds the length of the Text. Hence cannot be found. ");
        return 0;
    }
    int i, j = 0, count = 0;
    for(i = 0; i < lengthOfText; i++) {
        if(Text[i] == Pat[j] && j < lengthOfPat) {
            j++;
            /*If complete pattern is found. */
            if(j == lengthOfPat) {
                /*
                There can be possibility of start of new substring within the substring.
                Ex: if Text is ABABABA and Pat is ABAB.
                First substring starts at position 0 till position 3. But next substring could start from any position between 0 and 3.
                As in this case second substring starts at position 2 till position 5. To take this into account we decrement i by (lengthOfPat-1).
                */
                i = i - (lengthOfPat - 1);
                j = 0;
                count++;
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
    if(count > 0) {
        printf("\n %s occurred %d times", Pat, count);
        return 0;
    }
    else {
        printf("\n Pattern not found. ");
        return 0;
    }
}

int main(void) {
    char Text[] = "AABAACAADAABAABA";
    char Pat[] = "AABAB";
    count_occurrence_of_subsrting(Text, Pat);
    return 0;
}
