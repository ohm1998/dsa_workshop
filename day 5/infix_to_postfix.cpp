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
	return((c>='a' && c<='z') || (c>='A' && c<='Z'));
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

int priority(char op)
{
	if(op=='^')
		return 3;
	if(op=='*' || op=='/')
		return 2;
	if(op=='+' || op=='-')
		return 1;
	return 0;
}
int evaluate(char *exp)
{
	node *top = NULL;
	for(int i=0;exp[i]!='\0';i++)
	{
		//display_stack(top);
	//	printf("\n\n");
		char curr = exp[i];
		if(check_oper_alpha(curr))
		{
			printf("%c",curr);
		}
		else if(curr=='(')
		{
			push(&top,curr);
		}
		else if(curr=='+' || curr=='-' || curr=='*' || curr=='/' || curr=='^')
		{
			if(peek(top)=='(')
				push(&top,curr);
			else
			{
				if(priority(peek(top))<priority(curr))
				{
					push(&top,curr);
				}
				else
				{
					while(priority(peek(top))>=priority(curr) && !isEmpty(top))
					{
						printf("%c",peek(top));
						pop(&top);
					}
					push(&top,curr);
				}
			}
		}
		else if(curr==')')
		{
			while(peek(top)!='(' && !isEmpty(top))
			{
				printf("%c",peek(top));
				pop(&top);
			}
			pop(&top);
		}
	}
}
int main()
{
	char exp[100];
	scanf("%s",exp);
	evaluate(exp);
}
