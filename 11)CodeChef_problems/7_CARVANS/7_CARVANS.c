#include<stdio.h>
int main(void)
{
    int i, j, no_of_test_cases, no_of_cars, max_speed[10000], count, maximum;
    scanf("%d" ,&no_of_test_cases);
    for(i=0; i<no_of_test_cases; i++)
    {
        scanf("%d", &no_of_cars);
        for(j=0; j<no_of_cars; j++)
        {
            scanf("%d", &max_speed[j]);
        }
        maximum = max_speed[0];
        count = 1;
        for(j=1; j<no_of_cars; j++)
        {
            if(max_speed[j] < maximum)
            {
                maximum = max_speed[j];
                count++;
            }
        }
        printf("%d\n", count);

    }
    return(0);
}
