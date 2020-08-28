#include<stdio.h>

const int max = 100;
int stack[max],top=-1;


void push(int ele)
{
	top++;
	if(top==max)
	{
		printf("stack overflow");
		return ;
	}
	stack[top] = ele;
}
void pop()
{
	if(top==-1)
	{
		printf("Empty Stack");
	}
	else
	{
		top--;
	}
}
void display_stack()
{
	int ind = top;
	printf("\n->");
	while(ind>=0)
	{
		printf("%d \n",stack[ind]);
		ind--;
	}
}
int main()
{
		int num;
		while(num!=-1)
		{
			printf("Enter Number: \n");
			scanf("%d",&num);
			if(num==-1)
			{
				break;
			}
			else if(num==-2)
			{
				pop();
			}
			else
			{
				push(num);	
			}
			display_stack();
		}
}
