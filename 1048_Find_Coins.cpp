#include <iostream>
#define MAX 1001
using namespace std;

int main()
{
	int N,M,i,tmp,ans;
	int count[MAX];
	for(i=0;i<MAX;i++)
		count[i]=0;
	cin>>N>>M;
	for(i=1;i<=N;i++)
	{
		cin>>tmp;
		count[tmp]++;
	}
	bool has = false;
	for(i=1;i<=(M+1)/2;i++)
	{
		if(i!=(M-i))
		{
			if(count[i]!=0&&count[M-i]!=0)    //M-i可能大于500，所以数组要开1000+ 
			{
				ans = i;
				has=true;
			}
		}
		else if(i==M-i)
		{
			if(count[i]>=2)
			{
				ans = i;
				has = true;
			}
		}
		if(has)
			break;
	}
	if(has)
		cout<<ans<<" "<<M-ans<<endl;
	else
		cout<<"No Solution"<<endl;
	return 0;
}
