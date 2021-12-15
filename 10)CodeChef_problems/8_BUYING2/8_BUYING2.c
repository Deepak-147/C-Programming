#include<stdio.h>
int main(void)
{
    int i, j, no_of_test_cases, no_of_notes, cost_of_single_sweet, value_of_note[100], sum, remaining;
    scanf("%d", &no_of_test_cases);
    for(i=0; i<no_of_test_cases; i++)
    {
        scanf("%d", &no_of_notes);
        scanf("%d", &cost_of_single_sweet);
        sum = 0;
        for(j=0; j<no_of_notes; j++)
        {
            scanf("%d", &value_of_note[j]);
            sum = sum + value_of_note[j];
        }
        remaining = sum % cost_of_single_sweet;
        for(j=0; j<no_of_notes; j++)
        {
            if(value_of_note[j] <= remaining)
            {
                printf("-1\n");
                break;
            }
        }
        if(j == no_of_notes)
            printf("%d\n", sum / cost_of_single_sweet);
    }
    return(0);
}
