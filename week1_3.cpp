#include <stdio.h>
#include<stdlib.h>
int main(void) {
	int high,low,mid,n,m,i,j,x,flag=0;
	printf("enter size of 1st array\n");
	scanf("%d",&n);
	printf("enter size of 2nd array\n");
	scanf("%d",&m);
	printf("enter array\n");
	int arr[n][m];
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
		scanf("%d",&arr[i][j]);
	printf("enter element to be searched in the list\n");
	scanf("%d",&x);	
	low=0;
	high=(n*m)-1;
	while(high>=low){
		mid=(low+high)/2;
		if(arr[mid/m][mid % m] == x)
			{
				flag=1;
				break;
			}
		else if(arr[mid/m][mid % m]<x)
			low=mid+1;
		else
			high=mid-1;
	}
	if(flag==0)
		printf("the element could not be found\n");
	else
		printf("the row index is %d and column index is %d\n",mid/m,mid%m);
	return 0;
}
