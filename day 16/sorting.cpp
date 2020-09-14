#include<stdio.h>

void merge(int a[],int l1,int h1,int l2,int h2);
void mergeSort(int a[],int low,int high)
{
	int mid;
	if(low<high)
	{
		mid = (low+high)/2;
		mergeSort(a,low,mid);
		mergeSort(a,mid+1,high);
		merge(a,low,mid,mid+1,high);
	}
}
void merge(int a[],int l1,int h1,int l2,int h2)
{
	int i,j;
	i=l1;
	j=l2;
	int t=0;
	int temp[50];
	while(i<=h1 && j<=h2)
	{
		if(a[i]<a[j])
		{
			temp[t] = a[i];
			i++;
		}
		else
		{
			temp[t] = a[j];
			j++;
		}
		t++;
	}
	while(i<=h1)
	{
		temp[t] = a[i];
		t++;
		i++;
	}
	while(j<=h2)
	{
		temp[t] = a[j];
		j++;
		t++;
	}
	for(int x=l1,y=0;x<=h2;x++)
	{
		a[x] = temp[y];
		y++;
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
	mergeSort(a,0,n-1);
	for(int i=0;i<n;i++)
	{
		printf(" %d ",a[i]);
	}
}
