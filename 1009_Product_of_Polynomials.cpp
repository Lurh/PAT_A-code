#include <iostream>
#include <stdio.h>
#define MAX 10001
using namespace std;

int main()
{
	int i,j,tmp,num=0,N1,N2,M1,M2;
	double coe1[MAX],coe2[MAX],ans[MAX];
	for(i=0;i<MAX;i++)
		coe1[i]=0,coe2[i]=0,ans[i]=0;
	cin>>N1;
	for(i=1;i<=N1;i++)
	{
		cin>>tmp;
		cin>>coe1[tmp];
		if(i==1)
		M1=tmp;
	}
		
	cin>>N2;
	for(i=1;i<=N2;i++)
	{
		cin>>tmp;
		cin>>coe2[tmp];
		if(i==1)
		M2=tmp;
	}
	for(i=0;i<=M1;i++)
		for(j=0;j<=M2;j++)
			if(coe1[i]!=0&&coe2[j]!=0)
			ans[i+j]+=(coe1[i]*coe2[j]);	
	for(i=0;i<=M1+M2;i++)
		if(ans[i]!=0)
			num++;
	cout<<num;
	for(i=M1+M2;i>=0;i--)
		if(ans[i]!=0)
		printf(" %d %.1lf",i,ans[i]);
	cout<<endl;
	return 0;
 } 
