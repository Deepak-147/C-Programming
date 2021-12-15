/*Program to find duplicate number in an array. */
/*Approach 1: compare each element with all the other elements. */
/*T(n) = O(n^2) */

#include<stdio.h>
#include<conio.h>

int arr[10];
void arr_initialize(int array[], int array_size);
void duplicate(int array[], int array_size);
int main(void)
{
 int array_size = sizeof(arr)/sizeof(arr[0]);
 arr_initialize(arr, array_size);
 duplicate(arr, array_size);
 return(0);
}

void arr_initialize(int arr[], int array_size)
{
 int i;
 printf("Now input %d values to initialize array\n\n", array_size);
 for(i=0; i<array_size; i++)
 {
    printf("arr[%d]: ", i);
    scanf("%d", &arr[i]);
    printf("\n");
 }
}

void duplicate(int array[], int array_size)
{
 int i;
 int j;
 int flag = 0;
 if(array_size == 1)
 {
  printf("There is only one element in the array.\n");
 }
 else
 {
     for(i=0; i<array_size; i++)
     {
         for(j=i+1; j<array_size; j++)
         {
             if(arr[i] == arr[j])
             {
                flag = 1;
                printf("Duplicate exists!. At position %d and it's value is %d\n",j ,arr[j]);
             }
         }
     }
     if(flag == 0)
        printf("No duplicates found!\n");
 }
}
