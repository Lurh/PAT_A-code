#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stdio.h>
#define MAX 2510
#define LEN 4
using namespace std;

int main()
{
	int N,K,C,i,j,cour,num;
	vector<int> course[MAX],tmp;
	char name[LEN];
	scanf("%d%d",&N,&K);
	for(i=1;i<=N;i++)
	{
		
		scanf("%s %d",name,&C);
		num = (name[0]-'A')*26*26*10+(name[1]-'A')*26*10+(name[2]-'A')*10+name[3]-'0';
		for(j=1;j<=C;j++)
		{
			scanf("%d",&cour);
			course[cour].push_back(num);
		}
	}
	for(i=1;i<=K;i++)
	{
		tmp = course[i];
		sort(tmp.begin(),tmp.end());
		printf("%d %d\n",i,tmp.size());
		for(j=0;j<tmp.size();j++)
		{
			num = tmp.at(j);
			name[3]=char(num%10+'0');
			num/=10;
			name[2]=char(num%26+'A');
			num/=26;
			name[1]=char(num%26+'A');
			num/=26;
			name[0]=char(num%26+'A');
			printf("%s\n",name);
		}
	}
	return 0;
}
