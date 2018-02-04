#include <iostream>
#define MAX 1001
using namespace std;

int main()
{
	int i,j,N,M,K,C1,C2;
	bool highway[MAX][MAX];
	for(i=0;i<MAX;i++)
		for(j=0;j<MAX;j++)
			highway[i][j]=false;
	cin>>N>>M>>K;
	for(i=1;i<=M;i++)
	{
		cin>>C1>>C2;
		highway[C1][C2]=true;
		highway[C2][C1]=true;
	}
	return 0;
 } 
