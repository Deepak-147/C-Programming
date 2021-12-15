#include<stdio.h>
#include<math.h>
int main(void)
{
    int T, i;
    long int N, last_min, curr_min, root;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%ld", &N);
        root = sqrt(N);
        last_min = N - 1;
        for(i=2; i<=root; i++)
        {
            if((N%i) == 0)
            {
                curr_min = (N/i) - i;
                if(curr_min < 0)
                    curr_min = -curr_min;
                if(curr_min <= last_min)
                    last_min = curr_min;
            }
            else
                continue;
        }
        printf("%ld\n", last_min);
    }
    return(0);
}
