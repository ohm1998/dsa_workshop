#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	node *next;
};

void push(node **top,int ele)
{
	node * new_node = (node *)malloc(sizeof(node *));
	if(new_node==NULL)
	{
		printf("Stack Overflow");
		return ;
	}
	new_node->data = ele;
	new_node -> next = NULL;
	if((*top)==NULL)
	{
		*top = new_node;
	}
	else
	{
		new_node -> next = *top;
		*top = new_node;
	}
}

void display_stack(node *top)
{
	if(top==NULL)
	{
		printf("Empty Stack");
	}
	else
	{
		printf("->");
		while(top)
		{
			printf("%d \n",top->data);
			top = top->next;
		}
	}
}
int is_empty(node *top)
{
	if(top==NULL)
	{
		//printf("Stack Underflow");
		return 1;
	}
	return 0;
}
void pop(node **top)
{
	if(is_empty(*top))
	{
		return ;
	}
	else
	{
		node *temp = *top;
		*top = (*top)->next;
		free(temp);
	}
}
void peek(node *top)
{
	if(top)
	{
		printf("%d  \n",top->data);
		return ;
	}
	printf("Stack Empty!\n");
}
void reverse_stack(node **top)
{
	node *temp = NULL;
	while(!is_empty(*top))
	{
		int ele = (*top)->data;
		push(&temp,ele);
		pop(top);	
	}
	node *orig_top = *top;
	*top = temp;
	free(orig_top);
}
int main()
{
	node *top=NULL;

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
				pop(&top);
			}
			else if(num==-3)
			{
				reverse_stack(&top);
			}
			else
			{
				push(&top,num);
			}
			display_stack(top);
			//printf("Peek: \n");
			//peek(top);
		}
	return 0;
}
