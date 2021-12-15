#include<stdio.h>
#include<string.h>

int splitWords(char *inputText, char words[10][10]) {
    int n = 0, i, j = 0;
    for(i = 0; 1 ;i++) {
        if(inputText[i] != ' ') {
            words[n][j++] = inputText[i];
        }
        else {
            words[n][j++] = '\0';
            n++;
            j = 0;
        }
        if(inputText[i] == '\0')
            break;
    }
    return n;
}

void reverseWords(int noOfWords, char words[10][10], char reverse[10][10]) {
    int i;

    for(i = 0; i <= noOfWords; i++) {
        strcpy(reverse[i], strrev(words[i]));
    }
}

int main(void) {
    int noOfWords;
    char input[100], words[10][10], reverse[10][10];
    printf("Enter the input string: \n");
    gets(input);
    noOfWords = splitWords(input, words);
    printf("Number of words: %d\n", noOfWords);
    int i;
    for(i=0; i<=noOfWords; i++)
		printf("Words[%d]: %s\n", i, words[i]);

    reverseWords(noOfWords, words, reverse);

    for(i=0; i<=noOfWords; i++)
		printf("Reverse[%d]: %s\n", i, reverse[i]);

    int j;

    /*
    for(i = 0; i<=noOfWords; i++) {
        if(strlen(words[i]) == 1) {
            continue;
        }
        else {
           for(j = 0; j<=noOfWords; j++) {
                if(strcmp(words[i], reverse[j])){
                    printf("Correct word: %s\n", words[i]);
                    break;
                }
           }
        }
        break;
    }
    */
    printf("words[1]: %s\n", words[1]);
    printf("reverse[3]: %s\n", reverse[3]);

    printf("result: %d", strcmp(words[1], reverse[3]));
    return 0;
}
