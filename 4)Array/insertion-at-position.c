/*Program to insert element at a specific position in the array, position is given. */
/*Approach 1: First store the value at the position in the temp, then add new value to the position. Then move the elements one location to the right. */
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
 int temp;
 if(number+1 < SIZE)/* Check to see whether there is space in the array or not. */
 {
     int actual_index = position - 1;
     temp = arr[actual_index];
     arr[actual_index] = value;
     for(i=actual_index+1; i<=number; i++)
     {
      /* swap two variables temp and arr[i] without using third */
      temp = temp + arr[i];
      arr[i] = temp - arr[i];
      temp = temp - arr[i];
     }

 }
 printf("\nArray after insertion of the element at it's position: \n");
 for(i=0; i<number+1; i++)
 {
     printf("%d\n", arr[i]);
 }
}
