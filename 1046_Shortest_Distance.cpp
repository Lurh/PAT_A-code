#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#define MAX 100001
using namespace std;

int main()
{
	int N,M,i,j,l,sum=0,from,to,ans;
	vector<int> len;
	len.push_back(0);
	scanf("%d",&N);
	for(i=1;i<=N;i++)
	{
		scanf("%d",&l);
		sum+=l;
		len.push_back(sum);
	}
	scanf("%d",&M);
	for(i=1;i<=M;i++)
	{
		scanf("%d%d",&from,&to);
		if(from>to)
			swap(from,to);
		ans = abs(len.at(from-1)-len.at(to-1));
		if(ans>sum-ans)
			ans = sum - ans;
		printf("%d\n",ans);
	}
	return 0;
}
