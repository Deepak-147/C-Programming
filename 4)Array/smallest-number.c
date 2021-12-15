/*Program to find smallest number in an array*/
/*Approach 1: compare with each element by assuming first element as the smallest*/
/*T(n) = O(n) */

#include<stdio.h>
#include<conio.h>
int arr[10];
void arr_initialize(int array[], int array_size);
void small_pos(int array[], int array_size);

int main(void)
{
 int array_size = sizeof(arr)/sizeof(arr[0]);
 arr_initialize(arr, array_size);
 small_pos(arr,array_size);
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

void small_pos(int arr[], int array_size)
{
 int i;
 int small_index = 0;
 if(array_size == 1)
 {
  printf("There is only one element in the array.");
 }
 else
 {
 for(i=0; i<array_size; i++)
 {
    if(arr[i] < arr[small_index])
        small_index = i;
 }
 }
 printf("The index having smallest value is: %d\n\n", small_index);
 printf("The value corresponding to this index is: %d\n\n", arr[small_index]);
}


