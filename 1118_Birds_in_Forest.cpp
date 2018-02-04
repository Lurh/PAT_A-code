#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#define MAX 10010
using namespace std;
//应该使用并查集，本代码方法会在先出现的树中没有相关但后出现有相关时出错 
struct tree{
	vector<int> birds;
};

int main()
{
	vector<tree*> forest;
	tree *birds[MAX],*t,*t2;
	int N,K,Q,tmp,i,j,count=0;
	bool same_tree=false;
	for(i=0;i<MAX;i++)
		birds[i]=NULL;
	scanf("%d",&N);
	for(i=1;i<=N;i++)
	{
		scanf("%d",&K);
		t = new tree;
		same_tree = false;
		for(j=1;j<=K;j++)
		{
			scanf("%d",&tmp);
			t->birds.push_back(tmp);
			if(birds[tmp]!=NULL)
			{
				same_tree=true;
				t2 = birds[tmp];
			}	
		}
		if(same_tree)
		{
			for(j=0;j<t->birds.size();j++)
			{
				birds[t->birds[j]]=t2;
			}
			delete t;
		}
		else
		{
			t2 = t;
			for(j=0;j<t->birds.size();j++)
			{
				birds[t->birds[j]]=t2;
			}
			forest.push_back(t2);
		}
	}
	for(i=0;i<MAX;i++)
		if(birds[i]!=NULL)
			count++;
	printf("%d %d\n",forest.size(),count);
	scanf("%d",&Q);
	int b1,b2;
	for(i=1;i<=Q;i++)
	{
		scanf("%d%d",&b1,&b2);
		if(birds[b1]==birds[b2])
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
