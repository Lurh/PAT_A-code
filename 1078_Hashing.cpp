#include <iostream>
#include <stdio.h>
#include <vector>
#define MAX 20001  //MAX值不能只是大于10000，需要超过大于它的素数 
using namespace std;

bool isprime(int num)
{
	if(num%2==0)
		return false;
	for(int i=3;i*i<=num;i+=2)
		if(num%i==0)
			return false;
	return true;
}

int main()
{
	int M,N,i,j,tmp;
	vector<int> num;
	vector<int> ans;
	bool can[MAX];
	for(i=0;i<MAX;i++)
		can[i] = true;
	scanf("%d%d",&M,&N);
	if(M==1||M==0)
		M = 2;
	if(M!=2)
		for(M;;M++)
			if(isprime(M))
				break;
	for(i=1;i<=N;i++)
	{
		scanf("%d",&tmp);
		num.push_back(tmp);
	}
	bool has= false;
	for(i=0;i<num.size();i++)
	{
		has = false;
		for(j=0;j<M;j++)
		{
			tmp = (num.at(i)+j*j)%M;
			if(can[tmp])
			{
				ans.push_back(tmp);
				can[tmp]=false;
				has = true;
				break;
			}
		}		
		if(!has)
			ans.push_back(-1);
	}
	if(!ans.empty())
	{
		if(ans[0]!=-1)
			printf("%d",ans[0]);
		else
			printf("-");
	}
	if(ans.size()>1)
		for(i=1;i<ans.size();i++)
		{
			if(ans[i]!=-1)
				printf(" %d",ans[i]);
			else
				printf(" -");
		}	
	printf("\n");
	return 0;
 } 
