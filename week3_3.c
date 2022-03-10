#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void countsort(int n,int m, int j, int X, char a[n][m])
{
    char output[n][m], alpha[26] = "abcdefghijklmnopqrstuvwxyz", count[26]={0};
    int i, k, z;
    for(i=0; i<m; i++)
    {
        for(k=0; k<26; k++)
        {
            if(alpha[k] == a[j][i])
                count[k]++;
        }
    }
    for(k = 1; k<26; k++) 
        count[k] += count[k - 1];  
    for(i=0; i<m; i++) 
    {
        for(k=0; k<26; k++)
        {
            if(alpha[k] == a[j][i])
            {
                int y=count[k];
                for(z=j+2; z>=0; z--)
                {
                    output[z][y-1] = a[z][i];
                }
                count[k]--;
                break;
            }
        }
    }
    for(i=0; i<3; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("%c", output[j][i]);
        }
        printf(" ");
    } 
}
void radixsort(int n, int m, char a[n][m])
{
    int j;
    for(j=n-1;j>=0;j--)
    {
        int X = n-j-1;
        printf("\nAfter sorting with respect to the %dth element:\n",j);
        countsort(n,m,j,X,a);
    }
}
int main()
{
    int i, j, n, m;
    printf("Enter the number of words you wish to enter: ");
    scanf("%d",&m);
    printf("Enter the length of the words you wish to enter: ");
    scanf("%d",&n);
    char a[n][m];
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            scanf(" %c", &a[j][i]);
        }
    }
    radixsort(n,m,a);
}
