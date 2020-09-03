#include<stdio.h>
#include<stdlib.h>

struct node 
{
	int data;
	node *next;
};

struct stack
{
	node *top;	
};

void push(node **top,int ele)
{
	node *new_node = (node *)malloc(sizeof(node));
	new_node->data = ele;
	new_node->next = NULL;
	if(*top==NULL)
	{
		*top = new_node;
		return ;
	}
	new_node->next = *top;
	*top = new_node;
}

int isEmpty(node *top)
{
	if(top==NULL)
		return 1;
	return 0;
}

void display_stack(node *top)
{
	if(top==NULL)
	{
		return;
	}
	//printf("->");
	while(top)
	{
		printf("%d ->",top->data);
		top = top->next;
	}
}
void pop(node **top)
{
	if((*top)==NULL)
	{
		printf("Underflow \n");
	}
	node *temp = *top;
	*top = (*top)->next;
	free(temp);
}
void enqueue(node **top1,int ele)
{
	push(top1,ele);
}

int peek(node *top)
{
	return top->data;
}

void reverse_display(node *top)
{
	if(top==NULL)
		return ;
	stack temp;
	temp.top = NULL;
	node *curr = top;
	while(curr)
	{
		push(&(temp.top),peek(curr));
		curr = curr->next;
	}
	display_stack(temp.top);
}

void dequeue(node **top1,node **top2)
{
	if(isEmpty(*top2) && isEmpty(*top1))
	{
		printf("Queue Underflow");
	}
	else if(isEmpty(*top2))
	{
		printf("here");
		while(!isEmpty(*top1))
		{
			push(top2,peek(*top1));
			pop(top1);
		}
		pop(top2);
	}
	else
	{
		pop(top2);
	}
}
int main()
{
	stack s1,s2;
	s1.top = NULL;
	s2.top=NULL;
	int num=1;
	while(num)
	{
		scanf("%d",&num);
		if(num==-2)
		{
			dequeue(&(s1.top),&(s2.top));
		//	printf("S2: \n");
			display_stack(s1.top);
			reverse_display(s2.top);
		//	printf("S1: \n");
			printf("\n\n");
		}
		else
		{
			enqueue(&(s1.top),num);
		//	printf("S1: \n");
			display_stack(s1.top);
			reverse_display(s2.top);
		//	printf("S2: \n");
			printf("\n\n");
		}
		
	}
	return 0;
}
