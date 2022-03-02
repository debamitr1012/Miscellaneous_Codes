# include <bits/stdc++.h>
using namespace std;
int count(int arr[], int x, int n)
{
int *low = lower_bound(arr, arr+n, x);
if (low == (arr + n) || *low != x)
	return 0;
int *high = upper_bound(low, arr+n, x);	
return high - low;
}
int main()
{
	int z,x;
    printf("Enter the number of elements:");
    scanf("%d",&z);
    printf("Enter the array elements :");
    int arr[z];
    for(int i=0;i<z;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter the number :");
    scanf("%d",&x);
    int n = sizeof(arr)/sizeof(arr[0]);
    int c = count(arr, x, n);
    printf(" %d occurs %d times ", x, c);
    return 0;
	}
