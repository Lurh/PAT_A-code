#include <iostream>
#include <vector>
#include <stack>
#include <stdio.h>
#define MAX 100001
using namespace std;

struct node{
	int add,next,num;
	node()
	{
		add = -1,next = -1,num=0;
	}
	node(int address,int n, int nextn)
	{
		add = address,num = n, next = nextn;
	}
};


int main()
{
	int start,s,n,K,num;
	int i,j,id;
	node* place[MAX];
	for(i=0;i<MAX;i++)
		place[i]=NULL;
	vector<node*> original,sub,ans;
	stack<node*> tmp;
	//freopen("A.in","r",stdin);
	scanf("%05d%d%d",&start,&num,&K);
	node *tmpn;
	for(i=1;i<=num;i++)
	{
		scanf("%05d%d%05d",&s,&id,&n);
		tmpn = new node(s,id,n);
		place[s]=tmpn;
	}
	tmpn = place[start];
	while(1)
	{
		original.push_back(tmpn);
		if(tmpn->next==-1)
			break;
		tmpn = place[tmpn->next];
	}
	for(i=0;i<original.size();i++)
	{
		tmp.push(original.at(i));
		if((i+1)%K==0)
		{
			while(!tmp.empty())
			{
				ans.push_back(tmp.top());
				tmp.pop();
			}
		}
		else if(i==original.size()-1)
		{
			for(j=i-tmp.size()+1;j<original.size();j++)
				ans.push_back(original.at(j));
		}
	}
	for(i=0;i<ans.size()-1;i++)
			printf("%05d %d %05d\n",ans.at(i)->add,ans.at(i)->num,ans.at(i+1)->add);
	printf("%05d %d -1\n",ans.at(i)->add,ans.at(i)->num);
	return 0;
}
