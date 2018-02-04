#include <iostream>
#include <string>
#include <math.h>
#include <stack>
#include <queue>
using namespace std;

int main()
{
	
	int rad,i;
	long ori=0,rev=0;
	while(cin>>ori)
	{	
		if(ori<0)
		break;
		cin>>rad;
		bool isori=true,isrev=true;
		rev=0;
		queue<int> origin;
		if(ori<=1)
			isori=false;
		for(i=2;i<=int(sqrt(ori));i++)
			if(ori%i==0)
			{
				isori = false;
				break;
			}	
		while(ori>0)
		{
			origin.push(ori%rad);
			ori = (ori-ori%rad)/rad;
		}
		while(!origin.empty())
		{
			rev = rev*rad + origin.front();
			origin.pop();
		}
		if(rev<=1)
			isrev=false;
		for(i=2;i<=int(sqrt(rev));i++)
			if(rev%i==0)
			{
				isrev = false;
				break;
			}
		if(isrev&&isori)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}
