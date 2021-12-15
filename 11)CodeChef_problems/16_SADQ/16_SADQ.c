#include<stdio.h>
int main(void)
{
    int i, j, k, no_of_arrays, size[], M;
    scanf("%d", &no_of_arrays);

    for(i=1; i<=no_of_arrays; i++)
    {
        scanf("%d", &size[i]);
        int A[i][size];
        for(j=1; j<=size; j++)
        {
            scanf("%d", &A[i][j]);
        }
        scanf("%d", &M);
        int B[M][2];
        for(k=1; k<=M; k++)
        {
            scanf("%d %d", &B[k][1], &B[k][2]);
        }
        SAD(A, no_of_arrays, B, M);
    }
    return(0);
}

int SAD(int (*arr1)[COLS], int   rows1, int (*arr2)[COLS], int rows2)
{
    int i, j, k;
    for(i=1; i<=rows2; i++)
    {
        int index1 = *(*(q+i) + 1);// B[i][1]
        int index2 = *(*(q+i) + 2);// B[i][2]
        int size1 = sizeof(*(p+index1)) / sizeof(long);//sizeof(A[index1])/sizeof(A[0][0])
        int size2 = sizeof(*(p+index2)) / sizeof(long);//sizeof(A[index2])/sizeof(A[0][0])
        int diff = 0, sum;
        for(j=1; j<=size1; j++)
        {
            for(k=1; k<=size2; k++)
            {
                sum = ( *(*(p+index1)+j ) - *(*(p+index2)+k ) );//A[index1][j] - A[index2][k]
                if(sum<0)
                {
                    sum = -sum;
                }
                diff = diff + sum;
            }
        }
    return(diff);
    }
}
