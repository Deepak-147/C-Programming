#include<stdio.h>
int main(void)
{
    int T;
    long L, D, S, C, final_likes, i;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%ld %ld %ld %ld", &L, &D, &S, &C);
        final_likes = S;
        for(i = 1; i<D; i++)
        {
            final_likes = final_likes + C*final_likes;
            if(final_likes >= L)
                break;
        }
        if(final_likes >= L)
            printf("ALIVE AND KICKING\n");
        else
            printf("DEAD AND ROTTING\n");
    }
    return(0);
}
