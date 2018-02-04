#include <iostream>
#include <stack>
#include <queue>
#define MAX 1001
using namespace std;

int main()
{
	int M,N,K,i,j,tmp;
	queue<int> aim;
	stack<int> seq;
	bool can;
	cin>>M>>N>>K;
	for(i=0;i<K;i++)
	{
		can=true;
		for(j=0;j<N;j++)
		{
			cin>>tmp;
			aim.push(tmp);
		}
		for(j=1;j<=N;j++)
		{
			while(!seq.empty()&&(seq.top()==aim.front()))
			{
				aim.pop();
				seq.pop();
			}
			if(seq.size()<M)
			{	
				seq.push(j);
				continue;
			}
			else
			{
				can=false;
				break;
			}
		}
		while(!seq.empty())
			if(seq.top()!=aim.front())
			{
				can=false;
				break;
			}
			else
			{
				seq.pop();
				aim.pop();
			}
		if(can)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
		while(!aim.empty())
			aim.pop();
		while(!seq.empty())
			seq.pop();
	}
	return 0;
}
