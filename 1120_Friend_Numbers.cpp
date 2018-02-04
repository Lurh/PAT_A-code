#include <iostream>
#include <stdio.h>
#include <vector>
#include <cstring>
#define MAX 40
using namespace std;

int str2num(string str)
{
	int num=0;
	for(int i=0;i<str.size();i++)
	{
		num+=str[i]-'0';
	}
	return num;
}

int main()
{
	int N,i,num,count=0;
	string str;
	bool has[MAX];
	for(i=0;i<MAX;i++)
	{
		has[i]=false;	
	}
	scanf("%d",&N);
	for(i=1;i<=N;i++)
	{
		cin>>str;
		num = str2num(str);
		if(has[num])
			continue;
		else
		{
			has[num]=true;
			count++;
		}
	}
	printf("%d\n",count);
	bool first=true;
	for(i=0;i<MAX;i++)
	{
		if(has[i])
		{
			if(first)
			{
				printf("%d",i);
				first =false;
			}	
			else
				printf(" %d",i);
		}
	}
	printf("\n");
	return 0;
}
