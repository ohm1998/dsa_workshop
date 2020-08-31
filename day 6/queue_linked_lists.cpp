#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	node *next;
};

void enqueue(node **rear,node **front,int ele)
{
	node *new_node = (node *)malloc(sizeof(node));
	new_node->data = ele;
	new_node->next = NULL;
	if(*rear==NULL && *front==NULL)
	{
		//printf("Inside null condition");
		*rear = new_node;
		*front = new_node;
		//printf("front: %d and rear : %d",(*front)->data,(*rear)->data);
		return ;
	}
	new_node -> next = *rear;
	*rear = new_node;
}
void display_queue(node *rear,node *front)
{
	if(rear==NULL || front==NULL)
	{
		printf("Queue Empty \n\n");
		return ;
	}
	while(rear!=front)
	{
		printf("%d-> ",rear->data);
		rear = rear->next;
	}
	printf("%d \n\n",rear->data);
}
void dequeue(node **rear,node **front)
{
	if(*front==NULL || *rear==NULL)
	{
		printf("Queue Undeflow \n\n\n");
		return ;
	}
	if(*front==*rear)
	{
		*front = *rear = NULL;
		return ;
	}
	node *temp = NULL;
	node *r = *rear;
	while(r!=(*front))
	{
		temp = r;
		r = (r)->next;
	}
	node *t_free = *front;
	*front = temp;
	free(t_free);
	
}
int main()
{
	node *front=NULL,*rear=NULL;
	int num=0;
	do
	{
		printf("Element for Enqueue");
		scanf("%d",&num);
		if(num==-2)
		{
			dequeue(&rear,&front);
		}
		else
		{
			enqueue(&rear,&front,num);	
		}
		display_queue(rear,front);
	}while(num!=-1);
	return 0;
}
