#include  <stdio.h>
int readArray(int a[],int n)
{
    printf("Enter the elements: ");
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d",a+i);
    }
}
int binarySearch(int a[],int first,int last,int key)
{
    int mid,flag=0;
    while(first<=last)
    {
        mid = (first+last)/2;
        if(a[mid]==key)
        {
            printf("element found at pos %d",mid);
        }
        else if(a[mid]>key)
        {
            binarySearch(a,first,mid-1,key);
        }
        else
        {
            binarySearch(a,mid+1,last,key);
        }
        flag=1;
        break;
    }
    if(!flag)
    {
        printf("element not found");
    }
}
int main()
{
    int n,key;
    system("clear");
    printf("enter the number of elements: ");
    scanf("%d",&n);
    int a[n];
    readArray(a,n);
    printf("enter the key: ");
    scanf("%d",&key);
    binarySearch(a,0,n-1,key);
}
