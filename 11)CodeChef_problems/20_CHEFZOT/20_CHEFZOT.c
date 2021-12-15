#include<stdio.h>
int main(void)
{
    int i, no_of_elements, maximal_length = 0, index =-1, length;
    scanf("%d", &no_of_elements);
    int A[no_of_elements];
    for(i=0; i<no_of_elements; i++)
    {
       scanf("%d", &A[i]);
       if(A[i] == 0)
       {
            length = i - index;
            index = i;
            if(length-1 > maximal_length)
                maximal_length = length-1;
       }
       if(i == no_of_elements - 1)
       {
          length =  i - index;
          if(length > maximal_length)
                maximal_length = length;
       }
    }
    printf("%d\n", maximal_length);
    return(0);
}
