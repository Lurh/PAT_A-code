#include <iostream>
#include <cstring>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

struct person{
	string name,course;
	int marks;
	person(string n,string c,int m)
	{
		name = n,course = c,marks = m;
	}
};

bool cmp(person *p1,person *p2)
{
	if(p1->marks>p2->marks)
		return true;
	else if(p1->marks<p2->marks)
		return false;
	else
	{
		return p1->name<p2->name;
	}
}
int main()
{
	int N,i,marks,low,high;
	string name,course;
	vector<person*> list,ans;
	person *p;
	scanf("%d",&N);
	for(i=1;i<=N;i++)
	{
		cin>>name>>course;
		scanf("%d",&marks);
		p = new person(name,course,marks);
		list.push_back(p);
	}
	scanf("%d%d",&low,&high);
	for(i=0;i<list.size();i++)
		if(list.at(i)->marks>=low&&list.at(i)->marks<=high)
			ans.push_back(list.at(i));
	if(!ans.empty())
	{
		sort(ans.begin(),ans.end(),cmp);
		for(i=0;i<ans.size();i++)
			cout<<ans.at(i)->name<<" "<<ans.at(i)->course<<endl;
	}
	else
		printf("NONE\n");
	return 0;	
}
