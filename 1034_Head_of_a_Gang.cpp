#include <iostream>
#include <vector>
#include <cstring>
#include <stdio.h>
#include <queue>
#include <algorithm>
#define MAX 26*26*26+1
#define LEN 1001
using namespace std;

struct person{
	int id,total_time;
	vector<person*> to;
	vector<int> time;
	person(int id)
	{
		this->id = id,total_time = 0;
	}
};

int str2num(string str)
{
	return (str[0]-'A')*26*26+(str[1]-'A')*26+(str[2]-'A');
}

string num2str(int num)
{
	string str = "000";
	str[2] = num%26+'A';
	num = num/26;
	str[1] = num%26+'A';
	num = num/26;
	str[0] = num%26+'A';
	return str;
}

struct node{
	string str;
	int much;
	node(string s,int m)
	{
		str = s,much = m;
	}
};
bool compare(node n1,node n2)
{
	return n1.str<n2.str;
}
bool has_visit[MAX];
void init_has()
{
	for(int i=0;i<MAX;i++)
		has_visit[i]=false;
}
int num,max_time,place,sum_time;
void bfs(person *root)
{
	queue<person*> p;
	p.push(root);
	max_time=0,sum_time=0,place=0;
	num=0;
	while(!p.empty())
	{
		root = p.front();
		num++;
		has_visit[root->id]=true;
		sum_time+=root->total_time;
		if(root->total_time>max_time)
		{
			max_time=root->total_time;
			place = root->id;
		}
		for(int i=0;i<root->to.size();i++)
			if(has_visit[root->to.at(i)->id]==false)
				p.push(root->to.at(i)),has_visit[root->to.at(i)->id]=true;
		p.pop();
	}
}

int main()
{
	int N,K,i,j,t,n1,n2,sum;
	string str1,str2;
	person *p[MAX],*tmp1,*tmp2;
	vector<node> ans;
	
	for(i=0;i<MAX;i++)
		p[i] = NULL,has_visit[i]=false;
	scanf("%d%d",&N,&K);
	for(i=1;i<=N;i++)
	{
		cin>>str1>>str2;
		scanf("%d",&t);
		n1 = str2num(str1);
		n2 = str2num(str2);
		if(p[n1]==NULL)
			tmp1 = new person(n1);
		else
			tmp1 = p[n1];
		if(p[n2]==NULL)
			tmp2 = new person(n2);
		else
			tmp2 = p[n2];
		tmp1->to.push_back(tmp2);
		tmp1->time.push_back(t);
		tmp2->to.push_back(tmp1);
		tmp2->time.push_back(t);
		p[n1] = tmp1;
		p[n2] = tmp2;
	}
	for(i=0;i<MAX;i++)
		if(p[i]!=NULL)
		{
			sum = 0;
			for(j=0;j<p[i]->time.size();j++)
				sum+=p[i]->time.at(j);
			p[i]->total_time = sum;
		}
	for(i=0;i<MAX;i++)
		if(p[i]!=NULL&&has_visit[i]==false)
		{
			bfs(p[i]);
			if(num>=3&&sum_time/2>K)
			{
				str1 = num2str(p[place]->id);
				node n(str1,num);
				ans.push_back(n);
			}
		}
	sort(ans.begin(),ans.end(),compare);
	cout<<ans.size()<<endl;
	for(i=0;i<ans.size();i++)
		cout<<ans.at(i).str<<" "<<ans.at(i).much<<endl;
	return 0;
}
