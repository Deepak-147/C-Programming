#include<stdio.h>
int main(void)
{
    int T, i;
    long int N, K, teacher_count, student_count;
    scanf("%d", &T);
    for(i=0; i<T; i++)
    {
        scanf("%ld %ld", &N, &K);
        if(N==0 && K==0)
        {
            printf("%ld %ld\n", N, K);
        }
        else if(N==0 && K!=0)
        {
            printf("0 0\n");
        }
        else if(N!=0 && K == 0)
        {
            printf("0 %ld\n", N);
        }
        else
        {
            teacher_count = N%K;
            student_count = N/K;
            printf("%ld %ld\n", student_count, teacher_count);
        }
    }
    return(0);
}
