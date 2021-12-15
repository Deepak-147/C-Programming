#include<stdio.h>
#include<string.h>
void string_append(char *, char *);
int string_length(char *);
void change_case(char *);
int string_compare(char *, char *);
void string_reverse(char *);
void string_copy(char *, char *);
int string_substring(char *, char *);

int main(void)
{
    /* String functions without using library */
    int length, result;
    char s1[100], s2[100], s3[100], s11[100];

    printf("\nEnter string1 : ");
    gets(s1);

    printf("\nEnter substring to find in string 1 : ");
    gets(s11);

    printf("\nEnter string2 : ");
    gets(s2);

    printf("\nEnter string3 : ");
    gets(s3);

    result = string_substring(s1, s11);
    if(result == 1)
        printf("\n\n Whether %s is a substring of %s: YES", s11, s1);
    else
        printf("\n\n Whether %s is a substring of %s: NO", s11, s1);

    result = string_compare(s1, s2); /* Alternative: strcmp(s, t) compares string s with t, returns < 0 if s < t, 0 if s == t, > 0 if s > t */
    printf("\n\n Result of comparison between string1 and string2 is: %d", result);

    string_copy(s1, s3);    /*Alternative: strcpy(s, t) copies string s to string t*/
    printf("\n\n String3 after copying string1 is: %s", s3);

    string_reverse(s1);     /*Alternative: strrev(s) */
    printf("\n\n String1 after reversal is: %s", s1);

    string_append(s1, s2); /* Alternative: strcat(s1, s2) concatenates string s2 to s1 */
    printf("\n\n The given string1 after appending string2 is: %s", s1);

    length = string_length(s1);  /* Alternative: strlen(s) */
    printf("\n\n The length of the given string1 is: %d", length);

    change_case(s1); /* Alternative: toupper(s) and tolower(s) defined in ctype.h */
    printf("\n\n String1 after changing case is: %s", s1);

    return(0);
}
int string_length(char *s) {
    int count = 0;
    while(*s != '\0') {
        count++;
        s++;
    }
    return count;
}
/*
strlen: return length of string s

int strlen(char *s) {
    char *p = s;
    while(*p != '\0')
        p++;
    return p - s;
}

*/

void change_case(char *s) {
    while(*s != '\0') {
        if(*s == ' ') /*check for space, do nothing if space is encountered*/
            s++;
        if(*s >= 'A' && *s <= 'Z')  /*If it is in upper-case, then change it to lower-case */
            *s = *s + 32;
        else
            *s = *s - 32;   /*Otherwise change it to upper-case */
        s++;
    }
}

void string_append(char *s, char *t) {
    while(*s)
        s++;/* Find end of s */
    while(*t) {
        *s++ = *t++;
    }
    *s = '\0';
}

/*
strcpy: copy t to s

void strcpy(char *s, char *t) {
    while((*s++ = *t++)! = '\0')
        ;
}

*/

int string_compare(char *s, char *t) {
    while(*s == *t) {
        if(*s == '\0')
            return(0);
        s++;
        t++;
    }
    return(*s - *t);
}
/*
strcmp: returns < 0 if s < t, 0 if s == t, > 0 if s > t

int strcmp(char *s, char *t) {
    for( ; *s == *t; s++, t++)
        if(*s == '\0')
            return 0;
    return *s -*t;
}

*/

void string_reverse(char *s) {
    /*Both point to same*/
    char *original = s;
    int length = 0;

    /*This gets us the length of the string by traversing through s*/
    while(*s != '\0') {
        length++;
        s++;
    }

    /*s is now at the next location after the string Make s to point back to start again.*/
    s = original;
    char *p = s;

    /* Finds the end of the string*/
    while(*p != '\0')
        p++;
    /*We need the Index just before the null, which is the last index of string */
    p--;

    /*Swap contents pointed by s and p */
    while((*s != '\0')) {
        /*Basically for first run swap first and last index values, then second last with second index and so on. */
        *s = *s + *p;
        *p = *s - *p;
        *s = *s - *p;
        s++;
        p--;
        /*when value at both s and p are same and this pointer lies in mid-way of the whole string, then no need to swap further as we already have the reverse */
        if((*s == *p) && (s == original + (length)/2 ))
            break;
    }
    /*Bring the pointer s back to the starting place. */
    s = s - (length)/2;
}

void string_copy(char *s, char *t) {
    while(*s) {
        *t++ = *s++;
    }
    *t = '\0';
}

int string_substring(char *str, char *substr) {
    int flag = 0;
    while(*str != '\0') {
        if(*str == *substr && *substr != '\0') {
            str++;
            substr++;
        }
        else if(*substr == '\0') {
            flag = 1;
            break;
        }
        else {
            str++;
        }
    }
    return flag;
}
