#include<stdio.h>
void swap(int *a,int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b=temp;
}
void BubbleSort(int a[],int n)
{
	int swapped = 1;
	for(int i=0;i<n && swapped;i++)
	{
		swapped=0;
		for(int j=0;j<(n-1);j++)
		{
			if(a[j]>a[j+1])
			{
				swap(&a[j],&a[j+1]);
				swapped=1;
			}
		}
	}
}

void SelectionSort(int a[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		int min = a[i];
		int index = i;
		for(int j=i+1;j<n;j++)
		{
			if(a[j]>min)
			{
				min = a[j];
				index = j;
			}
		}
		swap(&a[i],&a[index]);
	}
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
	SelectionSort(a,n);
	for(int i=0;i<n;i++)
	{
		printf(" %d ",a[i]);
	}
}
