#include <iostream>
#include <cstring>
#include <stdio.h>
#include <vector>
#include <algorithm>
#define MAX 100010
#define LEN 8
using namespace std;

struct person{
	int id,grade;
	//char name[LEN];
	string name;
	person(int num,string str,int point)
	{
		id = num, name = str, grade = point;
	}
};

bool compare1(person* p1,person* p2)
{
	return p1->id<p2->id;	
}

bool compare2(person* p1,person* p2)
{
	if(p1->name<p2->name)
		return true;
	else if(p1->name>p2->name)
		return false;
	else
		return p1->id<p2->id;
	return false;
}

bool compare3(person* p1,person* p2)
{
	if(p1->grade<p2->grade)
		return true;
	else if(p1->grade>p2->grade)
		return false;
	else
		return p1->id<p2->id;
	return false;
}

int main()
{
	int N,C,i,id,point;
	string str;
	vector<person*> ans;
	person *tmp;
	scanf("%d%d",&N,&C);
	for(i=1;i<=N;i++)
	{
		scanf("%d",&id);
		cin>>str;
		scanf("%d",&point);
		tmp = new person(id,str,point);
		ans.push_back(tmp);
	}
	if(C==1)
		sort(ans.begin(),ans.end(),compare1);
	else if(C==2)
		sort(ans.begin(),ans.end(),compare2);
	else if(C==3)
		sort(ans.begin(),ans.end(),compare3);
	for(i=0;i<ans.size();i++)
	{
		printf("%06d ",ans.at(i)->id);
		cout<<ans.at(i)->name;
		printf(" %d\n",ans.at(i)->grade);
	}
	return 0;
}
