/**
* @tag     PAT_A_1020
* @authors Bob Lu (szlrhbob@163.com)
* @date    2017-06-20 15:58-17:19 
* @version 1.0 AC
* @Language C++
* @function null
*/ 

#include <iostream>
#include <vector>
#include <stdio.h>
#include <queue>
using namespace std;

vector<int> ans,seq;

struct node{
	node *left,*right;
	int num;
	node()
	{
		left = NULL;
		right = NULL;
		num = 0;
	}
	node(int num)
	{
		left = NULL;
		right = NULL;
		this->num = num;
	}
};
node *tree;

void bfs(node* root)
{
	queue<node*> q;
	q.push(root);
	node* tmp;
	while(!q.empty())
	{
		tmp = q.front();
		q.pop();
		ans.push_back(tmp->num);
		if(tmp->left!=NULL)
			q.push(tmp->left);
		if(tmp->right!=NULL)
			q.push(tmp->right);
	}
	return;
}

void buildtree(vector<int> post, vector<int> in, node* root,bool left)
{
	int r = post[post.size()-1];
	node* tmp;
	tmp = new node(r);
	seq.push_back(r);
	if(root==NULL)
		tree = tmp;
	else
	{
		if(left)
			root->left = tmp;
		else
			root->right = tmp;
	}
	int p = -1;
	for(int i=0;i<in.size();i++)
		if(in[i]==r)
		{
			p = i;
			break;
		}
	vector<int> left_post,right_post,left_in,right_in;
	for(int i=0;i<post.size()-1;i++)
		if(i<p)
			left_post.push_back(post[i]);
		else
			right_post.push_back(post[i]);
	for(int i=0;i<in.size();i++)
		if(i<p)
			left_in.push_back(in[i]);
		else if(i>p)
			right_in.push_back(in[i]);

//	for(int i=0;i<seq.size();i++)
//		cout<<seq[i];
	if(!left_post.empty())
		buildtree(left_post,left_in,tmp,1);
	if(!right_post.empty())
		buildtree(right_post,right_in,tmp,0);
	return;
}

int main()
{
	int n,i,tmp;
	vector<int> post,in;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&tmp);
		post.push_back(tmp);
	}
	for(i=0;i<n;i++)
	{
		scanf("%d",&tmp);
		in.push_back(tmp);
	}
	buildtree(post,in,tree,1);
	bfs(tree);
	if(!ans.empty())
		printf("%d",ans[0]);
	for(i=1;i<ans.size();i++)
		printf(" %d",ans[i]);
	printf("\n");
	return 0;
}
