#include<stdio.h>
int main(void)
{
    int i, j, a[1000], index, no_of_test_cases, no_of_jobs, no_of_jobs_completed;
    scanf("%d", &no_of_test_cases);
    if(no_of_test_cases > 50)
        return(0);
    else
    {
        for(i=0; i<no_of_test_cases; i++)
        {
            int flag = 0;
            scanf("%d %d", &no_of_jobs, &no_of_jobs_completed);
            if((no_of_jobs > 1000) || (no_of_jobs_completed > no_of_jobs))
                    return(0);
            else
            {
                for(j=0; j<no_of_jobs; j++)
                    a[j] = 0;
                for(j=0; j<no_of_jobs_completed; j++)
                {
                    scanf("%d", &index);
                    a[index-1] = 1;
                }
                for(j=0; j<no_of_jobs; j++)
                {
                    if(a[j] == 1)
                        continue;
                    if(flag == 0)
                    {
                        a[j] = 2;//for Chef
                        flag = 1;
                    }
                    else
                    {
                        a[j] = 3;//for Assistant
                        flag = 0;
                    }
                }
                for(j=0; j<no_of_jobs; j++)
                {
                    if(a[j] == 2)
                        printf("%d ", j+1);
                }
                printf("\n");
                for(j=0; j<no_of_jobs; j++)
                {
                    if(a[j] == 3)
                        printf("%d ", j+1);
                }
                printf("\n");
            }
        }
    }
    return(0);
}

