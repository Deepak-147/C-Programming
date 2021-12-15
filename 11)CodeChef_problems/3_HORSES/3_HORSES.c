#include<stdio.h>
int absolute(int);
int main(void)
{
    int no_of_test_cases, no_of_horses, s[5000], i, j, k, min_skill_difference, difference;
    scanf("%d", &no_of_test_cases);
    if(no_of_test_cases > 10)
        return(0);
    else
    {
        for(i=0; i<no_of_test_cases; i++)
        {
            scanf("%d", &no_of_horses);
            if((no_of_horses <= 1) || (no_of_horses > 5000))
                return(0);
            else
            {
               for(j=0; j<no_of_horses; j++)
               {
                   scanf("%d", &s[j]);
                   if((s[j] < 1) || (s[j] > 1000000000 ))
                        return(0);

               }
               min_skill_difference = s[0] - s[1];
               min_skill_difference = absolute(min_skill_difference);

               for(j=0; j<no_of_horses; j++)
               {
                   for(k = j+1; k<no_of_horses; k++)
                   {
                        difference = s[j] - s[k];
                        difference = absolute(difference);
                        if(difference < min_skill_difference)
                            min_skill_difference = difference;
                   }
               }
               printf("%d", min_skill_difference);
               printf("\n");

            }
        }
    }
    return(0);
}

int absolute(int a)
{
    if(a >= 0)
        return a;
    else
        return -a;
}
