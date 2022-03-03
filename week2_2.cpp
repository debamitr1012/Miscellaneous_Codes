#include <iostream>
using namespace std;
int ascendingBinarySearch(int arr[], int low, int high, int key)
{
	while (low <= high)
	{
		int mid = low + (high - low) / 2;
		if (arr[mid] == key)
			return mid;
		if (arr[mid] > key)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return -1;
}
int descendingBinarySearch(int arr[], int low, int high, int key)
{
	while (low <= high)
	{
		int mid = low + (high - low) / 2;
		if (arr[mid] == key)
			return mid;
		if (arr[mid] < key)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return -1;
}
int findBitonicPoint(int arr[], int n, int l, int r)
{
	int mid;
	int bitonicPoint = 0;
	mid = (r + l) / 2;
	if (arr[mid] > arr[mid - 1]	&& arr[mid] > arr[mid + 1])
	{
		return mid;
	}
	else if (arr[mid] > arr[mid - 1] && arr[mid] < arr[mid + 1])
	{
		bitonicPoint = findBitonicPoint(arr, n, mid, r);
	}

	else if (arr[mid] < arr[mid - 1] && arr[mid] > arr[mid + 1])
	{
		bitonicPoint = findBitonicPoint(arr, n, l, mid);
	}
	return bitonicPoint;
}
int searchBitonic(int arr[], int n, int key, int index)
{
	if (key > arr[index])
		return -1;
	else if (key == arr[index])
		return index;

	else {
		int temp
			= ascendingBinarySearch(arr, 0, index - 1, key);
		if (temp != -1) {
			return temp;
		}
		return descendingBinarySearch(arr, index + 1, n - 1, key);
	}
}
int main()
{
	int z, key;
    printf("Enter the number of elements :");
    scanf("%d",&z);
    printf("Enter the array elements :");
    int arr[z];
    for(int i=0;i<z;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter the element :");
    scanf("%d",&key);
	int n, l, r;
	n = sizeof(arr) / sizeof(arr[0]);
	l = 0;
	r = n - 1;
	int index;
	index = findBitonicPoint(arr, n, l, r);
	int x = searchBitonic(arr, n, key, index);
	if (x == -1)
		cout << "Element Not Found" << endl;
	else
		cout << "Element Found at index " << x << endl;
	return 0;
}
