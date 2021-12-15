/*Program to insert element at a specific position in the array, position is given. */
/*Approach 2: start from the last element of the array and continue shifting these elements one location to the right, then doing all shifts insert the given element at the specific position. */
/*T(n) = O(n) */

#include<stdio.h>
#include<conio.h>
#define SIZE 20
int arr[SIZE];
void arr_initialize(int array[], int number);
void insertion(int array[], int number, int value, int position);

int main(void)
{
 int value;
 int position;
 int number;
 printf("Enter the number of elements in the array: \n");
 scanf("%d", &number);
 arr_initialize(arr, number);
 printf("Enter the value to be inserted: \n");
 scanf("%d", &value);
 printf("Enter the position where to be inserted: \n");
 scanf("%d", &position);
 insertion(arr, number, value, position);

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

void insertion(int arr[], int number, int value, int position)
{
 int i;

 if(number+1 < SIZE)/* Check to see whether there is space in the array or not. */
 {
     int actual_index = position - 1;
     for(i=number; i>=actual_index; i--)
     {
         arr[i+1] = arr[i];
     }
     arr[actual_index] = value;

 }
 printf("\nArray after insertion of the element at it's position: \n");
 for(i=0; i<number+1; i++)
 {
     printf("%d\n", arr[i]);
 }
}
