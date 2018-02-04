#include <iostream>
#include <stdio.h>
#include <vector>
#include <cmath>
#define MAX 1005
using namespace std;

struct node{
	int r,c;
	node(int row,int col)
	{
		r = row,c = col;
	}
};

bool violate(node* n,int s,vector<node*> q)
{
	if(q.empty())
		return false;		
	int r=n->r,c=n->c;
	for(int i=0;i<q.size();i++)
	{
		if(c==q.at(i)->c)
			return true;
		if(abs(q.at(i)->r-r)==abs(q.at(i)->c-c))
			return true;	
		if(r+c==q.at(i)->r+q.at(i)->c)
			return true;
	}
	return false;
}

int main()
{
	int N,i,j,t,k,tmpn,c;
	node* n;
	vector<node*> q;
	bool can = true;
	scanf("%d",&N);
	for(t=1;t<=N;t++)
	{
		scanf("%d",&tmpn);
		can = true;
		for(k=1;k<=tmpn;k++)
		{
			scanf("%d",&c);
			n = new node(k,c);
			if(can&&violate(n,tmpn,q)==false)
				q.push_back(n);
			else
				can=false;
		}
		if(can)
			printf("YES\n");
		else
			printf("NO\n");
		for(i=0;i<q.size();i++)
			delete q.at(i);
		q.clear();
	}
	return 0;
}
