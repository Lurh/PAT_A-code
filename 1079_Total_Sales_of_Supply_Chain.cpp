#include <iostream>
#include <vector>
#include <queue> 
#include <stdio.h>
#include <math.h>
#define MAX 100010
using namespace std;

struct node{
	int id;
	int level,product;
	vector<node*> next;
	node(int num)
	{
		id = num, level = 0, product = 0;
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
	int N,K,i,j,id,count;
	double P,R,sum=0;
	node* place[MAX];
	bool retailers[MAX];
	for(i=0;i<MAX;i++)
		retailers[i]=false,place[i]= new node(i);
	scanf("%d%lf%lf",&N,&P,&R);
	for(i=0;i<N;i++)
	{
		scanf("%d",&K);
		if(K==0)
		{
			retailers[i]=true;
			scanf("%d",&id);
			place[i]->product=id;
		}
		else
			for(j=1;j<=K;j++)
			{
				scanf("%d",&id);
				place[i]->next.push_back(place[id]);
			}
	}
	bfs(place[0]);
	
	//for(i=0;i<N;i++)
	//	cout<<place[i]->next.size()<<" "<<place[i]->before.size()<<" "<<place[i]->level<<endl;
	for(i=0;i<N;i++)
	{
		if(retailers[i]==true)
		{
			sum+=pow(1+R*0.01,place[i]->level)*P*place[i]->product;
		}
	}
	printf("%.1lf\n",sum);
	return 0;
}
