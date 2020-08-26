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
	if(head==NULL)
	{
		printf("Empty List");
	}
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
void insert_pos(node **head,int pos,int val)
{
    node *new_node=(node*)malloc(sizeof(node));
    new_node->data=val;
    new_node->next=NULL;
    node *temp;
    node *p;
  //  printf("function call");
    if(pos==1)
    {
        if(*head==NULL)
        {
            *head=new_node;
        }
        else
		{
        	new_node -> next = *head;
			*head = new_node;	
		}
    }
    else{
    	//printf("here");
        temp=*head;
	    for(int i=1;i<pos;i++)
	    {
	        p=temp;
	        //printf("%d",temp->data);
	        temp=temp->next;
	        
	    }
	    p->next= new_node;
	    new_node->next=temp;
    }
}
void search(node *head,int ele)
{
	int count = 0;
    while(head)
	{
		if(head->data==ele)
		{
			printf("Element found at %d \n",count);
			return;
		}
		count++;
		//printf("%d ->",head->data);
		head = head->next;
	}
	printf("Element Not Found");
}
void delete_by_val(node **head,int val)
{
	node *curr = *head;
	node *prev = NULL;
	while(curr->data != val )
	{
		prev = curr;
		curr = curr->next;	
	}
	//printf("%d \n",curr->data);
	prev->next = curr->next;
	free(curr);
}
void delete_list(node **head)
{
	node *curr = *head;
	node *temp;
	while(*head)
	{
		temp = *head;
		*head = (*head)->next;
		free(temp);
	}
	//*head = NULL;
}
int main()
{
	node *head=NULL;
	insert_node(&head,13);
	insert_node(&head,15);
	insertion_beggin(&head,11);
	insertion_beggin(&head,9);
	insert_pos(&head,1,40);
	//search(head,11);
	display_list(head);
	printf("\n\n");
	delete_by_val(&head,11);
	delete_list(&head);
	display_list(head);
	return 0;
}
