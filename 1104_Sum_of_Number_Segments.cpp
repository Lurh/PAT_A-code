#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

int main()
{
	int N,i;
	double tmp,ans=0;
	scanf("%d",&N);
	for(i=1;i<=N;i++)
	{
		scanf("%lf",&tmp);
		ans+=tmp*i*(N-i+1);
	}
	printf("%.2lf\n",ans);
	return 0;
}
