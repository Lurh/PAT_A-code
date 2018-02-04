#include <iostream>
#include <queue>
#define MAX 10001
using namespace std;

int main()
{
	int N,i,tmp,exist[MAX];
	queue<int> bet;
	bool has=false;
	for(i=0;i<MAX;i++)
		exist[i]=0;
	cin>>N;
	while(N--)
	{
		cin>>tmp;
		bet.push(tmp);
		exist[tmp]++;
	}
	while(!bet.empty())
	{
		if(exist[bet.front()]==1)
		{
			has = true;
			tmp = bet.front();
			break;
		}
		bet.pop();
	}
	if(has)
		cout<<tmp<<endl;
	else
		cout<<"None"<<endl;
		
	return 0;
}
