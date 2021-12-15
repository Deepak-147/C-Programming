#include<stdio.h>
int main(void)
{
    int no_of_feedbacks;
    scanf("%d", &no_of_feedbacks);
    while(no_of_feedbacks--)
    {
        int i, flag = 0;
        char feedback[100000];
        scanf("%s", feedback);
        for(i=0; feedback[i] != '\0'; i++)
        {
            if( (feedback[i] == '0' && feedback[i+1] == '1' && feedback[i+2] == '0') || (feedback[i] == '1' && feedback[i+1] == '0' && feedback[i+2] == '1') )
            {
                flag = 1;
                break;
            }
        }
        if(flag == 1)
            printf("Good\n");
        else
            printf("Bad\n");
    }
    return(0);
}
