/*Program to delete an element at specific position from an array, position is given. */
/*Approach 1: From the given position shift the elements to the left by one position. */
/*T(n) = O(n) */

#include<stdio.h>
#include<conio.h>
#define SIZE 20
int arr[SIZE];
void arr_initialize(int array[], int number);
void deletion(int array[], int number, int value, int position);

int main(void)
{
 int value;
 int position;
 int number;
 printf("Enter the number of elements in the array: \n");
 scanf("%d", &number);
 arr_initialize(arr, number);
 printf("Enter the value to be deleted: \n");
 scanf("%d", &value);
 printf("Enter the position of deletion: \n");
 scanf("%d", &position);
 deletion(arr, number, value, position);

 return(0);
}

void arr_initialize(int arr[], int number)
{
 int i;

 printf("Now input %d values to initialize array\n\n", number);
 for(i=0; i<number; i++)
 {
    printf("arr[%d]: ", i);
    scanf("%d", &arr[i]);
    printf("\n");
 }
}

void deletion(int arr[], int number, int value, int position)
{
 int i;
 int actual_index = position-1;
 for(i=actual_index; i<number-1; i++)
 {
     arr[i] = arr[i+1];
 }
 number=number-1;
 printf("\nArray after deletion of the element at it's position: \n");
 for(i=0; i<number; i++)
 {
     printf("%d\n", arr[i]);
 }
}

