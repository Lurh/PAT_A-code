#include <iostream>
#include <vector>
#include <cstring>
#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;

int main()
{
	int N,i,j,place=0,tmp,num;
	string str;
	vector<int> stack,ans;
	//freopen("A.in","r",stdin);
	scanf("%d",&N);
	for(i=1;i<=N;i++)
	{
		cin>>str;
		if(str=="Push")
		{
			scanf("%d",&num);
			stack.push_back(num);
		}
		else if(str=="Pop")
		{
			if(stack.size()>0)
			{
				printf("%d\n",stack.at(stack.size()-1));
				stack.pop_back();
			}
			else
			{
				cout<<"Invalid"<<endl;
			}
		}
		else if(str=="PeekMedian")
		{
			if(stack.size()>0)
			{
				ans = stack;
				sort(ans.begin(),ans.end());
				if(stack.size()%2==0)
					printf("%d\n",ans.at(stack.size()/2-1));
				else
					printf("%d\n",ans.at((stack.size()-1)/2));
			}
			else
				cout<<"Invalid"<<endl;
		}
	}
	return 0;
}
