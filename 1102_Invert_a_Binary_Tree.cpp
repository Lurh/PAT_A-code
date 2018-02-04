#include <iostream>
#include <queue>
#include <stdio.h>
#define MAX 15
using namespace std;

struct node{
	int id;
	node *left,*right,*parent;
	node()
	{
		id = -1;
		left = NULL, right = NULL, parent = NULL;
	}
};

void disp(node *root)
{
	queue<node*> q;
	node *origin = root;
	q.push(root);
	while(!q.empty())
	{
		root = q.front();
		if(root->right!=NULL)
			q.push(root->right);
		if(root->left!=NULL)
			q.push(root->left);
		q.pop();
		if(root!=origin)
			printf(" %d",root->id);
		else
			printf("%d",root->id);
	}
}

void invert(node *root)
{
	node *tmp;
	tmp = root->left;
	root->left = root->right;
	root->right = tmp;
	if(root->left!=NULL)
		invert(root->left);
	if(root->right!=NULL)
		invert(root->right);
	return;
}
bool is = false;
void disp2(node *root)
{
	if(root->left!=NULL)
		disp2(root->left);
	if(is)
		printf(" %d",root->id);
	else
	{
		printf("%d",root->id);
		is = true;
	}
	if(root->right!=NULL)
		disp2(root->right);	
}
int main()
{
	int N,i;
	char l,r,tmp,tmp2;
	node *root;
	node *tree = new node[MAX];
	scanf("%d",&N);
	for(i=0;i<N;i++)
	{
		scanf("%c%c%c%c",&tmp2,&l,&tmp,&r);
		tree[i].id = i;
		if(l!='-')
		{
			tree[i].left = &tree[l-'0'];
			tree[l-'0'].parent = &tree[i];
		}
		if(r!='-')
		{
			tree[i].right = &tree[r-'0'];
			tree[r-'0'].parent = &tree[i];
		}
	}
	for(i=0;i<N;i++)
		if(tree[i].parent==NULL)
		{
			root = &tree[i];
			break;	
		}
	disp(root);
	printf("\n");
	invert(root);
	disp2(root);
	printf("\n");
	delete[] tree;
	return 0;
}
