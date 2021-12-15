#include<stdio.h>

/*
Pointer version
*/

void strCpy(char *s, char *t) {
    while(*s)
        *t++ = *s++;
    *t = '\0';
}


/*
Array version
*/

/*
void strCpy(char s[], char t[]) {
    int i = 0;
    while(s[i]) {
        t[i] = s[i];
        i++;
    }
    t[i] = '\0';
}

*/

int main(void) {
    char source[] = "Source";
    char destination[] = "Destination";

    /*Copies string source into string destination. */
    strCpy(source, destination);
    printf("String Destination is now: %s", destination);
    return 0;
}
