/*
 * Link: https://www.codechef.com/problems/DS2202?tab=statement
 */
#include <stdio.h>

void quick_sort(int arr[], int l, int h);

int main(void) {
	int n;
	scanf("%d", &n);
	
	int arr[n];
	
	for(int i = 0; i < n; i++)
	    scanf("%d", &arr[i]);
	 quick_sort(arr, 0, n-1);
	 for(int i = 0; i < n; i++)
	    printf("%d ", arr[i]);
	return 0;
}


int partition(int arr[],int l, int h)
{
    int i = l-1;
    int j = h+1;
    int pivot = arr[(l+h)/2];
    while(1)
    {
        while(arr[++i] < pivot);
        while(arr[--j] > pivot);
        
        if(i >= j)
            break;
        
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
    
    
    return j;
}

void quick_sort(int arr[], int l, int h)
{
    if(l >= h)
        return;
        
    int pivot = partition(arr, l, h);
    quick_sort(arr, l, pivot);
    quick_sort(arr, pivot+1, h);
}
