#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstring>
#define MAX 101
using namespace std;

struct node{
	int id,sum,weight,count;
	node *son[MAX];
	vector<int> route;
	node()
	{
		id = -1;
		sum = 0;
		count = 0;
	}
	node(int num,int weight)
	{
		id = num;
		this->weight = weight;
		sum = weight;
		count = 0;
	}
}; 

bool compare(vector<int> v1,vector<int> v2)
{
	for(int i=0;i<min(v1.size(),v2.size());i++)
	{
		if(v1.at(i)==v2.at(i))
			continue;
		else
			return v1.at(i)>v2.at(i);
	}
}

int main()
{
	int N,M,S,i,j,w,id,num,son;
	node *tree[MAX];
	node *n;
	scanf("%d%d%d",&N,&M,&S);
	for(i=0;i<N;i++)
	{
		scanf("%d",&w);
		n = new node(i,w);
		tree[i]=n;
	}
	tree[0]->route.push_back(tree[0]->weight);
	for(i=1;i<=M;i++)
	{
		scanf("%d%d",&id,&num);
		tree[id]->count = num;
		for(j=0;j<num;j++)
		{
			scanf("%d",&son);
			tree[id]->son[j]=tree[son];
			tree[son]->sum = tree[id]->sum+tree[son]->weight;
			tree[son]->route = tree[id]->route;
			tree[son]->route.push_back(tree[son]->weight);
		}
	}
	for(i=0;i<N;i++)
		if(tree[i]->count!=0)
		{
			for(j=0;j<tree[i]->count;j++)
			{
				if(tree[i]->son[j]->sum!=tree[i]->sum+tree[i]->son[j]->weight)
				{
					tree[i]->son[j]->sum=tree[i]->sum+tree[i]->son[j]->weight;
					tree[i]->son[j]->route = tree[i]->route;
					tree[i]->son[j]->route.push_back(tree[i]->son[j]->weight);
				}
			}
		}
	vector<vector<int> > ans; 
	for(i=0;i<N;i++)
		if(tree[i]->sum==S&&tree[i]->count==0)
			ans.push_back(tree[i]->route);
	sort(ans.begin(),ans.end(),compare);
	for(i=0;i<ans.size();i++)
	{
		printf("%d",ans.at(i).at(0));
		for(j=1;j<ans.at(i).size();j++)
		{
			printf(" %d",ans.at(i).at(j));
		}
		printf("\n");
	}
	return 0;
}
