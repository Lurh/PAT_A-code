#include <iostream>
#include <string>
#include <vector>
#define MAX 100000
using namespace std; 

long int str2lint(string str)
{
	long int num=0;
	if(str=="-1")
		return -1;
	for(int i=0;i<str.length();i++)
	{
		num = num*10 +str[i]-'0';
	}
	return num;
 } 

struct node{
	long int address;
	vector<long int> before;
	node()
	{
		address = 0;
	}
	node(long int n,long int add)
	{
		address = add, before.push_back(n);
	}
};

int main()
{
	long int i,first,second,N,tmp1,tmp2;
	string add1,add2,num;
	node *place[MAX];
	char ch;
	int count = 0;
	for(i=0;i<MAX;i++)
		place[i]=NULL;
	cin>>add1>>add2>>num;
	first = str2lint(add1);
	second = str2lint(add2);
	N = str2lint(num);
	for(i=1;i<=N;i++)
	{
		cin>>add1>>ch>>add2;
		tmp1 = str2lint(add1);
		tmp2 = str2lint(add2);
		if(tmp2==-1)
			tmp2=0,count++;
		node *p;
		if(place[tmp2]==NULL)
		{
			p = new node(tmp1,tmp2);
			place[tmp2]=p;
		}
		else 
		{
			p = place[tmp2];
			p->before.push_back((tmp1));
		}
	}
	if(count!=1)
		cout<<-1<<endl;
	else
	{
		tmp1 = 0;
		bool can=false;
		while(place[tmp1]->before.size()==1)
		{
		/*	if(tmp1==first)
			{
				while(place[place[tmp1]->before.at(0)]!=NULL)
				{
					tmp1 = place[tmp1]->before.at(0);
					if(tmp1==second)
					{
						can = true;
						tmp1 = first;
						break;
					}
				}
			}
			else if(tmp1==second)
			{
				while(place[place[tmp1]->before.at(0)]!=NULL)
				{
					tmp1 = place[tmp1]->before.at(0);
					if(tmp1==first)
					{
						can = true;
						tmp1 = first;
						break;
					}
				}
			}
			if(can)
				break;*/
			tmp1 = place[tmp1]->before.at(0);
		}
		cout<<tmp1<<endl;
	}
	return 0;
}
