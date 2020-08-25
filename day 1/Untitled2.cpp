#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	node *next;	
};
void insert_node(node **head,int val)
{
	node *new_node = (node *)malloc(sizeof(node));
	new_node->data = val;
	new_node->next = NULL;
	if(*head==NULL)
	{
		*head = new_node;
		return ;
	}
	node *curr = *head;
	while((curr->next)!=NULL)
	{
		curr = curr->next;
	}
	curr->next = new_node;
}
void display_list(node *head)
{
	while(head)
	{
		printf("%d ->",head->data);
		head = head->next;
	}
}
void insertion_beggin(node **head,int val)
{
	node * new_node = (node *)malloc(sizeof(node));
	new_node -> data = val;
	new_node -> next = *head;
	*head = new_node;
}
int main()
{
	node *head=NULL;
	insert_node(&head,13);
	insert_node(&head,15);
	insertion_beggin(&head,11);
	insertion_beggin(&head,9);
	display_list(head);
	return 0;
}
