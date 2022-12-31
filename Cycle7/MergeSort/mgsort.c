#include <stdio.h>

void printArray(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void merge(int A[], int mid, int low, int high)
{
    int i, j, k, B[100];
    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            B[k] = A[i];
            i++;
            k++;
        }
        else
        {
            B[k] = A[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        B[k] = A[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        B[k] = A[j];
        k++;
        j++;
    }
    for (int i = low; i <= high; i++)
    {
        A[i] = B[i];
    }
   
}

void mergeSort(int A[], int low, int high){
    int mid;
    if(low<high){
        mid = (low + high) /2;
        mergeSort(A, low, mid);
        mergeSort(A, mid+1, high);
        printArray(A, high+1);
        merge(A, mid, low, high);
    }
}

int main()
{
    int n,A[100];
    printf("enter the number of elements of the array ");
    scanf("%d",&n);
    printf("Enter the elements ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
    printf("the input array is \n");
    printArray(A, n);
    printf("\n");
    mergeSort(A, 0, n-1);
    printf("\n the sorted array is \n");
    printArray(A, n);
    return 0;
}
