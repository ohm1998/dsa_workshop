#include<stdio.h>


int FindPivot(int a[],int low,int high);
void QuickSort(int a[],int low,int high)
{
	int pivot;
	if(low<high)
	{
		pivot = FindPivot(a,low,high);
		QuickSort(a,low,pivot-1);
		QuickSort(a,pivot+1,high);
		
	}
}
void swap(int *a,int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b=temp;
}
int FindPivot(int a[],int low,int high)
{
	int left,right,pivot = a[low];
	left = low;
	right = high;
	while(left<right)
	{
		while(a[left]<=pivot)
		{
			left++;
		}
		while(a[right]>pivot)
		{
			right--;
		}
		if(left<right)
		{
			swap(&a[left],&a[right]);
		}
	}
	a[low] = a[right];
	a[right] = pivot;
	return right;
}

int main()
{
	int a[50],n;
	printf("Enter Size of Array: ");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	QuickSort(a,0,n-1);
	for(int i=0;i<n;i++)
	{
		printf(" %d ",a[i]);
	}
}
