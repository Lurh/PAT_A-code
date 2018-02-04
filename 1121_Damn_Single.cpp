#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#define MAX 100010
using namespace std;

int main()
{
	int N,p1,p2,tmp,i;
	int couple[MAX];
	bool occur[MAX];
	vector<int> come,ans;
	for(i=0;i<=MAX;i++)
	{
		couple[i]=-1;
		occur[i]=false;
	} 
	scanf("%d",&N);
	for(i=1;i<=N;i++)
	{
		scanf("%d%d",&p1,&p2);
		couple[p1]=p2;
		couple[p2]=p1;
	}
	scanf("%d",&N);
	for(i=1;i<=N;i++)
	{
		scanf("%d",&tmp);
		occur[tmp]=true;
		come.push_back(tmp);
	}
	for(i=0;i<come.size();i++)
		if(couple[come.at(0)]==-1)
			ans.push_back(come.at(i));
		else if(occur[couple[come.at(i)]]==false)
			ans.push_back(come.at(i));
	if(!ans.empty())
		sort(ans.begin(),ans.end());
	printf("%d\n",ans.size());
	if(!ans.empty())
		printf("%05d",ans.at(0));
	for(i=1;i<ans.size();i++)
		printf(" %05d",ans.at(i));
	//printf("\n");
	return 0;
}
