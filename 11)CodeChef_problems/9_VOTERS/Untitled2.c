#include<stdio.h>
int main(void)
{
    int N1, N2, N3, value, final_index, i;
    int array[150000] = {0};
    scanf("%d %d %d", &N1, &N2, &N3);
    for(i=0; i<N1+N2+N3; i++)
    {
        scanf("%d", &value);
        array[value]++;
    }
    final_index = 0;
    for(i=0; i<150000; i++)
        if(array[i] >= 2)
            final_index++;

    printf("%d\n", final_index);
    for(i=0; i<150000; i++)
        if(array[i] >= 2)
            printf("%d\n", i);

    return(0);
}
