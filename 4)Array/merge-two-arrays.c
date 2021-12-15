/*Program to merge two arrays into a third array, which is empty. */
/*Approach 1: First copy values from array1 to array3, then copy values of array2 to array3 such that values of array2 follows values of array1 and not overwrites them. */
/*T(n) = O(n)*/

#include<stdio.h>
#include<conio.h>
#define SIZE1 5
#define SIZE2 7
#define SIZE3 SIZE1+SIZE2
int arr1[SIZE1];
int arr2[SIZE2];
int arr3[SIZE3];
void arr_initialize(int array1[], int array2[], int number1, int number2);
void merge_array(int array1[], int array2[], int array3[], int number1, int number2);

int main(void)
{
 int num1, num2;
 printf("Array Size Limits:\n\n  Array1 Limit is %d, Array2 Limit is %d \n\n", SIZE1, SIZE2);
 printf("Enter the number of elements in the Array1 according to limits above: \n");
 scanf("%d", &num1);
 printf("Enter the number of elements in the Array2 according to limits above: \n");
 scanf("%d", &num2);
 arr_initialize(arr1, arr2, num1, num2);
 merge_array(arr1, arr2, arr3, num1, num2);
 return(0);
}

void arr_initialize(int arr1[], int arr2[], int num1, int num2)
{
 int i;

 printf("Now input %d values to initialize Array1\n\n", num1);
 for(i=0; i<num1; i++)
 {
    printf("arr[%d]: ", i);
    scanf("%d", &arr1[i]);
    printf("\n");
 }

 printf("Now input %d values to initialize Array2\n\n", num2);
 for(i=0; i<num2; i++)
 {
    printf("arr[%d]: ", i);
    scanf("%d", &arr2[i]);
    printf("\n");
 }
}

void merge_array(int arr1[], int arr2[], int arr3[], int num1, int num2)
{
 int i;
 int j;
 int num3 = num1+num2;
 for(i=0; i<num1; i++)
 {
     arr3[i] = arr1[i];
 }

 for(j=i, i=0; j<num3, i<num2; j++, i++)
 {
     arr3[j] = arr2[i];
 }
 printf("Contents of Merged Array3 are:\n\n");
 for(i=0; i<num3; i++)
 {
     printf("%d\n", arr3[i]);
 }
}
