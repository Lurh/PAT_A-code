#include <iostream>
#define MAX 48001
using namespace std;
int color[MAX];
int main()
{
	int M,N,i,j;
	long tmp,t;
	for(t=0;t<MAX;t++)
		color[t]=0;
	cin>>M>>N;
	for(i=0;i<M;i++)
		for(j=0;j<N;j++)
		{
			cin>>tmp;
			color[tmp%MAX]++;
		}
	tmp=0;
	int maxcount = 0;
	for(t=0;t<MAX;t++)
		if(maxcount<color[t])
		{
			tmp = t;
			maxcount = color[t];
		}
	cout<<tmp<<endl;
	
	return 0;		
}
