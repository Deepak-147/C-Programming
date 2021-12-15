/*Program to insert element in already sorted array, position is not given */
/*Approach 1: start from the first element of the array and check for the first element which is greater than our given value and store it's position in position variable. Then shift each element one location to the right and then put the value in its position. */
/*T(n) = O(n) */

#include<stdio.h>
#include<conio.h>
#define SIZE 20
int arr[SIZE];
void arr_initialize(int array[], int number);
void insertion_sorted(int array[], int number, int value);

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
 insertion_sorted(arr, number, value);

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

void insertion_sorted(int arr[], int number, int value)
{
 int i;
 int position;
 if(number+1 < SIZE)/* Check to see whether there is space in the array or not. */
 {
     for(i=0; i<number; i++)
     {
         if(arr[i] > value)
         {
             position = i;
             break;
         }

     }
     position = i;// Loop reached last element, but all values were small. So value needs to be put at last location.

     for(i=number; i>=position; i--)
     {
         arr[i+1] = arr[i];
     }
     arr[position] = value;
 }
 printf("\nArray after insertion of the element at it's position: \n");
 for(i=0; i<number+1; i++)
 {
     printf("%d\n", arr[i]);
 }
}
