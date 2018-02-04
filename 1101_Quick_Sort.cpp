#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#define MAX 100010
using namespace std;

int main()
{
	vector<long int> origin,ans;
	long int left[MAX],right[MAX];
	long int N,i,min,max,count=0,tmp;
	scanf("%ld",&N);
	for(i=1;i<=N;i++)
	{
		scanf("%ld",&tmp);
		origin.push_back(tmp);
	}
	max = origin.at(0);
	min = origin.at(N-1);
	for(i=0;i<N;i++)
	{
		if(max<origin.at(i))
			max = origin.at(i);
		left[i]=max;
	}
	for(i=N-1;i>=0;i--)
	{
		if(min>origin.at(i))
			min = origin.at(i);
		right[i]=min;
	}
	for(i=0;i<N;i++)
	{
		if(left[i]<=origin.at(i)&&right[i]>=origin.at(i))
		{
			count++;
			ans.push_back(origin.at(i));
		}
	}
	sort(ans.begin(),ans.end());
	printf("%ld\n",count);
	if(!ans.empty())
		printf("%ld",ans.at(0));
	for(i=1;i<ans.size();i++)
		printf(" %ld",ans.at(i));
	printf("\n");
	return 0;
} 
