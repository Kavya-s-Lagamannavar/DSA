//Searching a number in a sorted array using Binary search

#include <stdio.h>

int binarysearch (int a[], int n , int x , int s , int e)
{
    if (s>e)
    {
        return 0 ;
    }
    int mid = (e+s)/2 ;
    if(x== a[mid] || x==a[e] || x==a[s])
        return 1 ;

    else if(x>mid )
    {
        s = mid+1 ;
        binarysearch (a,n,x,s,e);
    }

    else
    {
        e = mid-1 ;
        binarysearch (a,n,x,s,e);
    }
}

int main ()
{
    int a[100], n,x, s = 0,e, f= 0;

    printf("Enter the number of elements: ");
    scanf ("%d", &n);
    e = n-1;

    printf("Enter a sorted array : \n");
    for (int i =0 ;i<n ; i++)
    {
        scanf("%d",&a[i]);
    }

    printf("Enter the number to be searched: ");
    scanf ("%d",&x);

    f = binarysearch (a,n,x,s,e);

    if (f == 0)
    {
        printf("Element not found");
    }

    else if (f==1)
    {
        printf("Element found");
    }
}
