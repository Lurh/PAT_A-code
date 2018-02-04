#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int n,i,tmp,num=-1,ans0[10000];
	double coe[10000],ans1[10000],tmp1;
	for(i=0;i<10000;i++)
		coe[i]=0;
	for(int t=1;t<=2;t++)
	{
		cin>>n;
		for(i=1;i<=n;i++)
		{
			cin>>tmp>>tmp1;
			coe[tmp]+=tmp1;
		}
	}
	for(i=1000;i>=0;i--)
	{
		if(coe[i]!=0)
		{
			num++;
			ans0[num]=i;
			ans1[num]=coe[i];
		}
	}
	cout<<num+1;
	for(i=0;i<=num;i++)
		printf(" %d %.1lf",ans0[i],ans1[i]);
	cout<<endl;
	return 0;
 } 
