/*Program to delete an element from an array, position is not given */
/*Approach 1: First find out the position of the value which is to be deleted(using outer for loop) and when that element is located store it's position in position variable, then loop from that position to the end of the array and keep shifting elements towards left. */
/*T(n) = O(n) */

#include<stdio.h>
#include<conio.h>
#define SIZE 20
int arr[SIZE];
void arr_initialize(int array[], int number);
void deletion(int array[], int number, int value);

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
 deletion(arr, number, value);

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

void deletion(int arr[], int number, int value)
{
 int i;
 int position;

 for(i=0; i<number; i++)// To find out the position of the element
 {
     if(arr[i] == value)
     {
         position = i;
		 break;
	 }
 }

 for(i=position; i<number-1; i++)// To shift the elements to the right, after the position is found
 {
     arr[i] = arr[i+1];
 }
 number = number-1;

 printf("\nArray after deletion of the element at it's position: \n");
 for(i=0; i<number; i++)
 {
     printf("%d\n", arr[i]);
 }
}
