#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int main()
{
	int i;
	double W[3],T[3],L[3],sum=1;
	char ans[3],source[3]={'W','T','L'};
	for(i=0;i<3;i++)
	{
		cin>>W[i]>>T[i]>>L[i];
		if(W[i]>T[i]&&W[i]>L[i])
		{
			ans[i]='W';
			sum*=W[i];
		}		
		else if(T[i]>W[i]&&T[i]>L[i])
		{
			ans[i]='T';
			sum*=T[i];
		}
		else if(L[i]>W[i]&&L[i]>T[i])
		{
			ans[i]='L';
			sum*=L[i];
		}
	}
	for(i=0;i<3;i++)
	cout<<ans[i]<<" ";
	printf("%.2f",(sum*0.65-1)*2+0.001);	
	return 0;
}
