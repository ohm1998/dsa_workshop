#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	node *next;
};

void insert_data(node **head,int val)
{
	node * new_node = (node *)malloc(sizeof(node *));
	new_node -> data = val;
	new_node -> next = *head;
	if(*head == NULL)
	{
		*head = new_node;
	}
	else
	{
		node *curr = *head;
		while((curr->next!=(*head)))
		{
			curr = curr->next;
		}
		curr->next = new_node;
	}
}

void display_list(node *head)
{
	node *curr = head;
	do
	{
		printf("%d ->",curr->data);
		curr = curr->next;
	}while(curr!=head);
}

int main()
{
	node *head = NULL;
	insert_data(&head,20);
	insert_data(&head,30);
	insert_data(&head,40);
	display_list(head);
	return 0;
}
