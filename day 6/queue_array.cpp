#include<stdio.h>

int queue[100],front=-1,rear=-1;

void display_queue()
{
	if(front==-1)
	{
		return ;
	}
	int r=rear,f=front;
	while(r<=f)
	{
		printf("%d ->",queue[r]);
		r++;
	}
}
void enqueue(int ele)
{
	if(rear==-1 && front==-1)
	{
		rear = 0;
		front=0;
		queue[front] = ele;
		return ;
	}
	queue[++front] = ele;
}
void dequeue()
{
	if(rear==-1)
	{
		printf("Queue Underflow");
		return ;
	}
	if(rear==front)
	{
		rear=-1;
		front= -1;
		return ;
	}
	rear++;
}
int main()
{
	int num=1;
	while(num)
	{
		printf("Enter Enqueue ele : ");
		scanf("%d",&num);
		if(num == -1)
		{
			dequeue();
		}
		else
		{
			enqueue(num);
		}
		display_queue();
	}
	return 0;
}
