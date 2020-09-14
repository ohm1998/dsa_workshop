#include<stdio.h>

void towerOfHanoi(int n,char start='A',char dest='C',char aux='B')
{
	if(n==1)
	{
		printf("from %c to %c \n",start,dest);
		return ;
	}
	towerOfHanoi(n-1,start,aux,dest);
	printf("Send disc from %c to %c \n",start,dest);
	towerOfHanoi(n-1,aux,dest,start);
}

int main()
{
	int n=3;
	towerOfHanoi(n,'A','C','B');
}
