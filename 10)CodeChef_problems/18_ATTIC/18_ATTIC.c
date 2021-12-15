#include<stdio.h>
int main(void)
{
    long int no_of_test_cases, no_of_days, practice_steps, no_of_dots, i, k;
    scanf("%ld", &no_of_test_cases);
    while(no_of_test_cases--)
    {
        no_of_days = 0;
        no_of_dots = 0;
        practice_steps = 0;
        char P[1000000];
        scanf("%s", P);
        for(i=0; P[i] != '\0'; i++)
        {
            if(P[i] == '.')
            {
                no_of_dots = 1;
                k = i+1;
                while(P[k] == '.')
                {
                    no_of_dots++;
                    k++;
                }
                if(no_of_dots > practice_steps)
                {
                    practice_steps = no_of_dots;
                    no_of_days++;
                }
                i = k-1;
            }
        }
        printf("%ld\n", no_of_days);
    }
    return(0);
}
