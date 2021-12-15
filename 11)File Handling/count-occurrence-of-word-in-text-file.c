/*
Please provide text file name in the command line argument. Or set the value of command line argument in the IDE.
Keep the text file in the same directory as the .c file.
*/

#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 1000

int countWord(FILE *f, char *word) {
    char str[BUFFER_SIZE];
    int index, count = 0;
    char *position;
    /*read the file line by line. */
    while (fgets(str, BUFFER_SIZE, f) != NULL) {
        index = 0;

        /*Find next occurrence of word in str. */
        while ((position = strstr(str + index, word)) != NULL) {
            index = (position - str) + 1;
            count++;
        }
    }
    return count;
}

int main(int argc, char *argv[]) {

    int word_count;
    char word[100];

    if(argc == 1)
        printf("\n Please provide a name of the text file as input");

    else if(argc == 2) {
        FILE *f = fopen(argv[1], "r");
        if(!f) {
            printf("\n Error opening file. ");
            exit(-1);
        }
        printf("\n Enter word to be counted: ");
        scanf("%s", word);
        word_count = countWord(f, word);
        printf("\n %s occurred %d times ", word, word_count);
    }
    return 0;
}
