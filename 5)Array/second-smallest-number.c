/*Program to find second smallest number in an array*/
/*Approach 1: compare each element assuming first element to be smallest to find smallest element(first smallest) element in the array, then simply don't compare the first smallest element with other elements to get the second smallest element*/
/*T(n) = O(n) */

#include<stdio.h>
#include<conio.h>

int arr[10];
void arr_initialize(int array[], int array_size);
void second_smallest(int array[], int array_size);

int main(void)
{
 int array_size = sizeof(arr)/sizeof(arr[0]);
 arr_initialize(arr, array_size);
 second_smallest(arr, array_size);
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

void second_smallest(int arr[], int array_size)
{
 int i;
 int first_small = 0;
 int second_small = 0;
 if(array_size == 1)
 {
  printf("There is only one element in the array.");
 }
 else
 {
  for(i=0; i<array_size; i++)
  {
     if(arr[i] < arr[first_small])
        first_small = i;

  }
  for(i=0; i<array_size; i++)
  {
     if( (arr[i] < arr[second_small]) && (arr[i] != arr[first_small]) )
        second_small = i;
  }
 }
 printf("The index having second smallest value is: %d\n\n", second_small);
 printf("The value corresponding to this index is: %d\n\n", arr[second_small]);
}
