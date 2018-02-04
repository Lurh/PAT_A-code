#include <iostream>
#include <vector>
#include <queue>
#include <stdio.h>
#define MAX 110
using namespace std;

struct person{
	int level;
	vector<person*> parents;
	vector<person*> children;
	person()
	{
		level = 0;
	}
};

void bfs(person* root)
{
	int count[MAX],i;
	for(i=0;i<MAX;i++)
		count[i]=0;
	queue<person*> tree;
	root->level=1;
	tree.push(root);
	while(!tree.empty())
	{
		root = tree.front();
		if(!root->parents.empty())
			root->level=root->parents.at(0)->level+1;
		count[root->level]++;
		for(i=0;i<root->children.size();i++)
			tree.push(root->children.at(i));
		tree.pop();
	}
	int num=0,gen=0;
	for(i=1;i<MAX;i++)
	{
		if(count[i]>num)
		{
			gen = i;
			num = count[i];
		}
	}
	printf("%d %d\n",num,gen);
}


int main()
{
	int N,M,i,j,id,num;
	vector<person*> family;
	person *p,*child;
	scanf("%d%d",&N,&M);
	for(i=0;i<=N;i++)
	{
		p = new person;
		family.push_back(p);
	}
	for(i=1;i<=M;i++)
	{
		scanf("%d%d",&id,&num);
		p = family.at(id);
		for(j=1;j<=num;j++)
		{
			scanf("%d",&id);
			child = family.at(id);
			p->children.push_back(child);
			child->parents.push_back(p);
		}
	}
	for(i=1;i<=N;i++)
	{
		if(family.at(i)->parents.empty())
		{
			p = family.at(i);
			break;
		}
	}
	bfs(p);
	return 0;
}
