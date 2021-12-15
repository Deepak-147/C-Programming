#include<stdio.h>

/*
Pointer version
*/


int strCmp(char *s, char *t) {
    while(*s++ == *t++){
        /*
        If both characters are equal and if one of the pointer points to null.
        It means other also points at null. This concludes that both strings are equal.
        */
        if(*s == '\0')
            return 0;
    }
    return(*s - *t);
}


/*
Array version
*/

/*
int strCmp(char s[], char t[]) {
    int i = 0;
    int j = 0;
    while(s[i++] == t[j++]) {
        if(s[i] == '\0')
            return 0;
    }
    return (s[i] - t[j]);
}
*/

int main(void) {
    char source[] = "Source";
    char destination[] = "Destination";

    /*
    Use of conditional expression using Ternary operator. If both the strings are equal, our function returns 0. And same of given as output.
    Otherwise the difference their ASCII values is returned as output.
    */
    printf("\n\n Result of comparison between string1 and string2 is: %d", (strCmp(source, destination) == 0)? 0: strCmp(source, destination));
    return 0;
}

