#include <iostream>
#include <vector>
#include <queue> 
#include <stdio.h>
#include <math.h>
#define MAX 100010
using namespace std;

struct node{
	int id;
	int level;
	vector<node*> next;
	node(int num)
	{
		id = num, level = 0;
	}
};

void bfs(node* root)
{
	queue<node*> search;
	search.push(root);
	while(!search.empty())
	{
		root = search.front();
		for(int i=0;i<root->next.size();i++)
		{
			root->next.at(i)->level = root->level+1;
			search.push(root->next.at(i));
		}
		search.pop();
	}
}
int main()
{
	int N,K,i,j,id,count,w;
	double P,R,sum=0;
	node* place[MAX];
	bool retailers[MAX];
	for(i=0;i<MAX;i++)
		retailers[i]=false,place[i]= new node(i);
	scanf("%d%lf%lf",&N,&P,&R);
	for(i=0;i<N;i++)
	{
		scanf("%d",&K);
		if(K!=-1)
			place[K]->next.push_back(place[i]);
		else
			w = i;
	}
	bfs(place[w]);
	double max = 0;
	w = 0;
	for(i=0;i<N;i++)
	{
		if(place[i]->next.empty())
		{
			if(max<pow(1+R*0.01,place[i]->level)*P)
			{
				max = pow(1+R*0.01,place[i]->level)*P;
				w = 1;
			}
			else if(max==pow(1+R*0.01,place[i]->level)*P)
			{
				w++;
			}		
		}
	}
	printf("%.2lf %d\n",max,w);
	return 0;
}
