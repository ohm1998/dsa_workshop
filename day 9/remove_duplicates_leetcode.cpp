#include<stdio.h>
char * removeDuplicates(char * S){

    char stack[200];
    int top=-1;
    int i=0;
    while(S[i]!='\0')
    {
        if(top==-1)
        {
            top++;
            stack[top] = S[i];
        }
        else
        {
            if(stack[top]==S[i])
            {
                top--;
            }
            else
            {
                top++;
                //printf("%c",S[i]);
                stack[top] = S[i];
            }
        }
        i++;
    }
    i=0;
    while(i<=top)
    {
        printf("%c",stack[i]);
        i++;
    }
    stack[++top] = '\0';
    return stack;
}

int main()
{
	char s[10000] = removeDuplicates("abbaca");
	printf("%s",s);
}
