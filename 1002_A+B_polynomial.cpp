#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int i,j,l=-1,n,p;
	float exp[50],coe[50],tmp,tmp2;
	for(i=0;i<50;i++)
	{
		exp[i]=0;
		coe[i]=0;
	}
	for(int t=2;t>0;t--)
	{
		cin>>n;
		for(i=0;i<n;i++)
		{
			cin>>tmp>>tmp2;
			bool has=false;
			for(j=0;j<=l;j++)
				if(exp[j]==tmp)
				{
					has=true;
					coe[j]+=tmp2;
					break;	
				}
			if(has==false)
			{
				l++;
				exp[l]=tmp;
				coe[l]+=tmp2;
			}	
		}
	}
	for(i=0;i<=l;i++)
	{
		for(j=0;j<l;j++)
		{
			if(exp[j]<exp[j+1])
			{
				tmp=coe[j];
				coe[j]=coe[j+1];
				coe[j+1]=tmp;
				
				tmp=exp[j];
				exp[j]=exp[j+1];
				exp[j+1]=tmp;
			}
		}
	}
	cout<<l+1;
	for(i=0;i<=l;i++)
		if(exp[i]-int(exp[i])!=0)
			printf(" %2.1f %2.1f",exp[i],coe[i]);
		else
			printf(" %d %2.1f",int(exp[i]),coe[i]);
	return 0;
}
