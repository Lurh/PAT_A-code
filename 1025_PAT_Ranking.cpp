#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;

struct person{
	string id;
	int mark,queue_num,final_rank,local_rank;
	person()
	{
		id = "",mark=-1,queue_num=-1,final_rank=-1,local_rank=-1;
	}
	person(string id0,int mark0,int q)
	{
		id = id0,mark=mark0,queue_num=q,final_rank=-1,local_rank=-1;
	}
};

bool compare(person p1,person p2)
{
	return (p1.mark>p2.mark) ;
}

vector<person> setlocalrank(vector<person> p)
{
	p.at(0).local_rank=1;
	for(int i=1;i<p.size();i++)
	{
		if(p.at(i).mark==p.at(i-1).mark)
			p.at(i).local_rank = p.at(i-1).local_rank;
		else
			p.at(i).local_rank = i+1;
	//	cout<<p.at(i).mark<<" "<<p.at(i).local_rank<<endl;
	}
	return p;
}

vector<person> setfinalrank(vector<person> p)
{
	p.at(0).final_rank=1;
	for(int i=1;i<p.size();i++)
	{
		if(p.at(i).mark==p.at(i-1).mark)
			p.at(i).final_rank = p.at(i-1).final_rank;
		else
			p.at(i).final_rank = i+1;
	}
	return p;
}
int main()
{
	int N,M,i,j,sum=0,points;
	string str;
	vector<vector<person> > lists;
	vector<person> total_list;  
	cin>>N;
	for(int t=1;t<=N;t++)
	{
		cin>>M;
		sum+=M;
		vector<person> one_list;
		while(M--)
		{
			person *p;
			cin>>str>>points;
			p = new person(str,points,t);
			one_list.push_back(*p);
		}
		lists.push_back(one_list);
	}
	
	for(i=0;i<lists.size();i++)
		sort(lists.at(i).begin(),lists.at(i).end(),compare);
	for(i=0;i<lists.size();i++)
		lists.at(i)=setlocalrank(lists.at(i));
	for(i=0;i<lists.size();i++)
		for(j=0;j<lists.at(i).size();j++)
			total_list.push_back(lists.at(i).at(j));
	sort(total_list.begin(),total_list.end(),compare);
	total_list = setfinalrank(total_list);
	cout<<sum<<endl;
	for(i=0;i<sum;i++)
		cout<<total_list.at(i).id<<" "<<total_list.at(i).final_rank<<" "<<total_list.at(i).queue_num<<" "<<total_list.at(i).local_rank<<endl;
	return 0;
}
