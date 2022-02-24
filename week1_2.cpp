#include <stdio.h> 
#include <stdbool.h>
#define MAX 100000 
void printPairs(int arr[], int arr_size, int sum) 
{ 
  int i, temp; 
  bool s[MAX] = {0};
  for (i = 0; i < arr_size; i++) 
  { 
      temp = sum - arr[i]; 
      if (temp >= 0 && s[temp] == 1) 
         printf("Pair with given sum %d is (%d, %d) \n",  
                 sum, arr[i], temp); 
      s[arr[i]] = 1; 
  } 
} 
int main() 
{ 
    int z,n;
    printf("Enter the number of elements:");
    scanf("%d",&z);
    printf("Enter the array elements :");
    int A[z];
    for(int i=0;i<z;i++)
    {
        scanf("%d",&A[i]);
    }
    printf("Enter the number :");
    scanf("%d",&n);
    int arr_size = sizeof(A)/sizeof(A[0]); 
    printPairs(A, arr_size, n); 
    getchar(); 
    return 0; 
}
