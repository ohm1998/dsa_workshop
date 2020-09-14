#include<stdio.h>
#include<stdlib.h>
#include<queue>
using namespace std;
struct node
{
	int data;
	node *left;
	node *right;
};

node * new_node(int val)
{
	node *  new_node = (node *)malloc(sizeof(node));
	new_node->data = val;
	new_node->left = NULL;
	new_node->right = NULL;
	return new_node;
}

node * insert_node(node *root,int val)
{
	if(root==NULL)
	{
		node *ele = new_node(val);
		root = ele;
		return root;
	}
	if(root->data<val)
	{
		root->right = insert_node(root->right,val);
	}
	else if(root->data>val)
	{
		root->left = insert_node(root->left,val);
	}
	return root;
}

void inorder(node *root)
{
	if(root==NULL)
	{
		return ;
	}
	inorder(root->left);
	printf(" %d ",root->data);
	inorder(root->right);
}
void preorder(node *root)
{
    if(root==NULL)
        return;
    printf(" %d ",root->data);
    preorder(root->left);
    preorder(root->right);
}
void postorder(node *root)
{
    if(root==NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf(" %d ",root->data);
}
node * search(node *root,int ele)
{
	if(root==NULL)
	{
		return root;
	}
    if(root->data==ele)
        return root;
    else if(root->data<ele)
        return search(root->right,ele);
    else if(root->data>ele)
        return search(root->left,ele);
}
node * max_ele(node *root)
{
	if(root==NULL)
	{
		return root;
	}
	if(root->right)
	{
		return max_ele(root->right);
	}
	return root;
}
node *min_ele(node *root)
{
	if(root==NULL)
	{
	return root;
	}
	if(root->left)
	{
	      return min_ele(root->left);
	}
	return root;
	
}
int height(node *root)
{
	if(root==NULL)
	{
		return 0;
	}
	int left = height(root->left);
	int right = height(root->right);
	int max = left>right?left:right;
	return (max+1);
}
void level_order_traversal(node *root)
{
	queue<node*> q;
	q.push(root);
	while(q.empty()==0)
	{
		node *ele = q.front();
		printf(" %d ",ele->data);
		if(ele->left)
		{
			q.push(ele->left);
		}
		if(ele->right)
		{
			q.push(ele->right);
		}
		q.pop();
	}
}

node * delete_ele(node *root,int val)
{
	if(root==NULL)
	{
		printf("Element Not Found");
		return root;
	}
	else
	{
		if(val>root->data)
			root->right = delete_ele(root->right,val);
		else if(val<root->data)
			root->left = delete_ele(root->left,val);
		else
		{
				if(root->left==NULL && root->right==NULL)
				{
					free(root);
					return NULL;
				}
				else if(root->left==NULL)
				{
					return root->right;
				}
				else if(root->right==NULL)
				{
					return root->left;
				}
				else
				{
					node *temp = min_ele(root->right);
					root->data = temp->data;
					root->right = delete_ele(root->right,temp->data);
					return root;
				}
		}	
	}
}

int main()
{
	node *root=NULL;
	int n=1;
	while(n)
	{
		scanf("%d",&n);
		if(n==-2)
		{
			scanf("%d",&n);
			//node *res = search(root,n);
			root = delete_ele(root,n);
			inorder(root);
			continue;
			/*if(res)
			{
				printf("Element Exists \n");
				printf("Height of ele is : %d ",height(res));
			}
			else
			{
				printf("Element Doesn't Exist");
			}
			continue;*/
		}
		root = insert_node(root,n);
		inorder(root); printf("\n\n");
		preorder(root); printf("\n\n");
		postorder(root); printf("\n\n");
		printf("\n\n");
	}
	/*node *ele = min_ele(root);
	printf("\n min ele is : %d ",ele->data);*/
	printf("\n Height of the tree is %d ",height(root));
	return 0;
}
