/*Demostrates String reading method using getc, getchar, getche, getch */
#include<stdio.h>
#include<conio.h>
int main(void) {
    char ch_1 = getc(stdin);//We need to specify Input stream with getc, it can work with both standard and console input. It echoes the character and waits for ENTER
    printf("\n Entered Character is: %c\n", ch_1);

    char ch_2 = getchar();//No need to specify Input stream with getchar as it works with only standard input stream
    printf("\n Entered Character is: %c\n", ch_2);

    char ch_3 = getche();//Echoes the inputted character, but does not require an ENTER to terminate
    printf("\n Entered Character is: %c\n", ch_3);

    char ch_4 = getch();//Does not echoes the inputted character, and does not require an ENTER to terminate
    printf("\n Entered Character is: %c\n", ch_4);

    return(0);
}
/*
getchar()
Declaration : int getchar(void);

Gets a character (an unsigned char) from stdin.
On success the character is returned. If the end-of-file is encountered, then EOF is returned and the end-of-file indicator is set.
If an error occurs then the error indicator for the stream is set and EOF is returned.

getc()
Declaration : int getc(FILE *stream);
Gets the next character (an unsigned char) from the specified stream and advances the position indicator for the stream.
On success the character is returned. If the end-of-file is encountered, then EOF is returned and the end-of-file indicator is set. If an error occurs then the error indicator for the stream is set and EOF is returned.

getche()
It accepts character from the keyboard and displays it on the console immediately, without even waiting for the enter key to be pressed.

getch()
It just accepts a keystroke and never displays it and proceeds further. Normally we use it at the end of the main ( ).
*/

/*
The difference between getchar() and getc(FILE *stream) is that, getc can read input from any stream, while getchar can only read from the standard input. Thus you can say that
getchar() = getc(stdin)
*/
