/*Demonstrates various string read and write methods. */
#include<stdio.h>
#include<conio.h>
int i = 0;
char ch, str[20];
void Read_Method1();
void Read_Method2();
void Read_Method3();
void Read_Method4();

void Write_Method1();
void Write_Method2();
void Write_Method3();

int main(void)
{
    Read_Method1();
    Write_Method1();
    Write_Method2();
    Write_Method3();


    Read_Method2();
    Write_Method1();
    Write_Method2();
    Write_Method3();


    Read_Method3();
    Write_Method1();
    Write_Method2();
    Write_Method3();


    Read_Method4();
    Write_Method1();
    Write_Method2();
    Write_Method3();


    return(0);
}
void Read_Method1()
{
    printf("\n\n Reading using Method 1 ");
    printf("\n\n Enter a string: ");
    scanf("%s", str);// Terminates after a blank space, and also does not require ampersand(&) before the variable str
}

void Read_Method2()
{
    fflush(stdin);// Flush the input buffer otherwise the newline character from previous scanf becomes input to gets()
    printf("\n\n Reading using Method 2 ");
    printf("\n\n Enter a string: ");
    gets(str);// Takes even strings with blank space. But does not check the maximum limit of input characters, so at any time compiler may return buffer overflow error.
}
void Read_Method3()
{
    int i = 0;
    printf("\n\n Reading using Method 3 ");
    printf("\n\n Enter a string: ");
    ch = getchar();//Get a character
    while(ch != '\n')
    {
        str[i] = ch;//Store the read character in the str
        i++;
        ch = getchar();//Get another character
    }
    str[i] = '\0'; //Terminate str with null character
}

void Read_Method4()
{
   printf("\n\n Reading using Method 4 ");
   printf("\n\n Enter a string: ");
   fgets(str, 20, stdin);
   /* It reads a line from the specified stream and stores it into the string pointed to by str. It stops when either (n-1) characters are read, the newline character is read, or the end-of-file is reached, whichever comes first. */
   /* It is safe to use because it checks the array bound. */
}


void Write_Method1()
{
    printf("\n\n Writing using Method 1: %s\n", str);
}

void Write_Method2()
{
    printf("\n\n Writing using Method 2:");
    puts(str);
}

void Write_Method3()
{
    printf("\n\n Writing using Method 3:");
    i=0;
    while(str[i] != '\0')
    {
        putchar(str[i]);//Print character on the screen
        i++;
    }
}

