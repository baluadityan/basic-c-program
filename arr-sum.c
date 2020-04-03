#include<stdio.h>
int main()
{
   int array[] = {1,2,3,4,5,6,7};
   int sum;
   sum = sum_array_elements(array,6);
   printf("\nSum of array elements is:%d",sum);
   return 0;
}
int sum_array_elements( int arr[], int n ) {
   if (n < 0) {
    return 0;
   } else{
     return arr[n] + sum_array_elements(arr, n-1);
    }
}