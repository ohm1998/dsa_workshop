#include<stdio.h>
#include<stdlib.h>

struct node
{
	char c;
	node *next;
};

void push(node **top, char val)
{
	//printf("%c",val);
	node *new_node = (node *)malloc(sizeof(node *));
	new_node->c = val;
	new_node->next = *top;
	*top = new_node;
}

int pop(node **top)
{
	if((*top)==NULL)
	{
		return -1;
	}
	*top = (*top)->next;
	return 1;
}

int check_oper_alpha(char c)
{
	return((c>='a' && c<='z') || (c>='A' && c<='Z') || c=='+' || c=='-' || c=='*' || c=='/' || c=='^');
}
int isEmpty(node *top)
{
	if(top==NULL)
		return 1;
	return 0;
}
char peek(node *top)
{
	return top->c;
}
void display_stack(node *top)
{
	printf("->");
	while(top)
	{
		printf("%c \n",top->c);
		top= top->next;
	}
}
int check_expression(node **top,char *s)
{
	for(int i=0;s[i]!='\0';i++)
	{
		char curr = s[i];
		if(!check_oper_alpha(curr))
		{
			//printf("if");
			if(curr=='(')
			{
				push(top,curr);
			}
			else if(curr==')')
			{
				if(isEmpty(*top))
					return -1;
				else if(peek(*top)=='(')
					pop(top);
				else
					return -1;
			}
		}
	//	display_stack(*top);
	}
	if(isEmpty(*top))
	{
		//printf("over here");
		return 1;
	}
	return -1;
}

int main()
{
	node *top = NULL;
	char s[100];
	scanf("%s",s);
	/*push(&top,'(');
	push(&top,')');*/
	int result = check_expression(&top,s);
	printf("%d",result);
	//display_stack(top);
	return 0;
}
