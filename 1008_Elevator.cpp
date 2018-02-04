#include <iostream>
#define MAX 10001
using namespace std;

int main()
{
	int i,N,sum_t;
	int queue[MAX];
	int gap[MAX];
	for(i=0;i<MAX;i++)
	{
		queue[i]=0;
		gap[i]=0;
	}
		
	cin>>N;
	for(i=1;i<=N;i++)
	{
		cin>>queue[i];
		gap[i]=queue[i]-queue[i-1];
	}
	sum_t = N*5;
	for(i=1;i<=N;i++)
		if(gap[i]>0)
			sum_t+=6*gap[i];
		else if(gap[i]<0)
			sum_t+=-4*gap[i];
	cout<<sum_t<<endl;
	return 0;
}
