#include<stdio.h>
int main(void)
{
    int sum, i, N, result;
    long int C[100000];
    scanf("%d", &N);
    sum = 0;
    for(i=0; i<N; i++)
    {
        scanf("%ld", &C[i]);
        sum = sum + C[i];
    }
    result = (N*(N+1)) / 2;
    if(sum == result)
        printf("YES\n");
    else
        printf("NO\n");

    return(0);
}
