#include<stdio.h>
int main(void)
{
    /*Method 1*/
    struct student
    {
        int roll_no;
        char name[20];
        char branch[20];
    };
    struct student s1;
    printf("%d\n\n", sizeof(s1));
    printf("%d\n\n", sizeof s1);
    printf("%d\n\n", sizeof (struct student));

    /*Method 2*/
    struct data
    {
        int dd;
        int mm;
        int yy;
    } s2;
    printf("%d\n\n", sizeof(s2));
    printf("%d\n\n", sizeof s2);
    printf("%d\n\n", sizeof (struct data));

    /*Method 3*/
    typedef struct
    {
        char first_name[10];
        char middle_name[10];
        char last_name[10];
    } name;/*struct is type defined to be as name, so hereafter we can use name n1 instead of struct name n1, to declare an object n1*/
    name n1;
    printf("%d\n\n", sizeof(n1));
    printf("%d\n\n", sizeof n1);
    printf("%d\n\n", sizeof (name));


    return(0);
}

