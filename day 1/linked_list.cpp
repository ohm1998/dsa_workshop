#include<iostream>
using namespace std;

struct node
{
	int data;
	node *next;	
};
void insert_node(node **head,int val)
{
	node *new_node = new node;
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
		cout<<head->data<<"->";
		head = head->next;
	}
}
int main()
{
	node *head=NULL;
	insert_node(&head,13);
	insert_node(&head,15);
	display_list(head);
	return 0;
}
