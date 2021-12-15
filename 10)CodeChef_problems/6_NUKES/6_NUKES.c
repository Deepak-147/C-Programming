#include <stdio.h>
int main(void)
{
    int A, N, K, i, mod;
    scanf("%d %d %d", &A, &N, &K);
    for(i=0; i<K; i++)
    {
        mod = A%(N+1);
        printf("%d ", mod);
        A = A/(N+1);
    }
    printf("\n");
    return(0);
}
