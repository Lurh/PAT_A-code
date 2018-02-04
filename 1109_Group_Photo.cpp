#include <iostream>
#include <stdio.h>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>
#define MAX 15
using namespace std;

struct person{
	int height;
	string name;
	person(string n,int h)
	{
		height = h,name = n;
	}
};

bool cmp(person *p1,person *p2)
{
	if(p1->height>p2->height)
		return true;
	else if(p1->height<p2->height)
		return false;
	else
		return p1->name<p2->name;
}

int main()
{
	int N,i,j,h,row,begin,m;
	string name;
	vector<person*> q,ans[MAX],sub;
	queue<person*> left;
	stack<person*> right;
	person* p;
	scanf("%d%d",&N,&row);
	for(i=1;i<=N;i++)
	{
		cin>>name;
		scanf("%d",&h);
		p = new person(name,h);
		q.push_back(p);
	}
	m = floor(N/row);
	if(!q.empty())
		sort(q.begin(),q.end(),cmp);
	begin=0;
	if(!q.empty())
	{
		for(j=1;j<=row;j++)
		{
			if(j==1)
			{
				for(i=begin;i<begin+m+N%m;i++)
					sub.push_back(q.at(i));
				begin = begin + N%m;
			}
			else
				for(i=begin;i<begin+m;i++)
					sub.push_back(q.at(i));
			begin = begin + m;
			for(i=0;i<sub.size();i++)
			{
		    	if(i%2==0)
		    		left.push(sub.at(i));
		    	else
		    		right.push(sub.at(i));
			}
			while(!right.empty())
			{
				ans[j].push_back(right.top());
				right.pop();
			}
			while(!left.empty())
			{
				ans[j].push_back(left.front());
				left.pop();
			}
			sub.clear();
		}
		for(j=1;j<=row;j++)
		{
			sub = ans[j];
			cout<<sub.at(0)->name;
			if(sub.size()>1)
				for(i=1;i<sub.size();i++)
					cout<<" "<<sub.at(i)->name;
			cout<<endl;
		}
	}
	return 0;
} 
