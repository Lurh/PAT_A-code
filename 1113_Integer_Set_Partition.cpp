#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;

int main() 
{
	int N,K,i,j,tmp,sum=0;
	vector<int> input;
	scanf("%d",&N);
	for(i=1;i<=N;i++)
	{
		scanf("%d",&tmp);
		input.push_back(tmp);
	}
	sort(input.begin(),input.end());
	K = input.size();
	for(i=0;i<input.size();i++)
		if(i<K/2)
			sum-=input.at(i);
		else
			sum+=input.at(i);
	printf("%d %d\n",K%2==0?0:1,sum);
	return 0;
}
