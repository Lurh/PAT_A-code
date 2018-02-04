//didn't pass 
#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int n,i,tmp,j;
	double num[1002]={0},tmp1;
	bool p[1002] = {false};
	for(i=0;i<1002;i++)
	{
		num[i]=0;
		p[i]=false;
	}
	for(j=2;j>0;j--)
	{
		cin>>n;
		for(i=0;i<n;i++)
		{
			cin>>tmp;
			p[tmp]=true;
			cin>>tmp1;
			num[tmp]+=tmp1;
		}
	}
	tmp=0;
	for(i=0;i<1002;i++)
		tmp+=p[i];
	cout<<tmp;
	for(i=1001;i>=0;i--)
		if(p[i]==true)
		printf(" %d %.1lf",i,num[i]);
	cout<<endl;

	return 0;
 } 
