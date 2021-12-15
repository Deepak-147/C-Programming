#include<stdio.h>
long int find_max(long int *, long int);
int main(void)
{
    long int no_of_turns, no_of_values;
    scanf("%ld %ld", &no_of_values, &no_of_turns);
    long int max, i, A[no_of_values], j;
    if(no_of_turns != 0)
    {
        if((no_of_turns%2) == 1)
            no_of_turns = 1;
        else
            no_of_turns = 2;
    }
    for(i=0; i<no_of_values; i++)
        scanf("%ld", &A[i]);
    for(i=0; i<no_of_turns; i++)
    {
        max = find_max(A, no_of_values);
        for(j=0; j<no_of_values; j++)
            A[j] = max - A[j];
    }
    for(i=0; i<no_of_values; i++)
        printf("%ld ", A[i]);
    return(0);
}
long int find_max(long int *ptr, long int no_of_values)
{
    long int i, max = 0;
    for(i=0; i<no_of_values; i++)
    {
        if(*ptr > max)
            max = *ptr;
        ptr++;
    }
    return(max);
}

