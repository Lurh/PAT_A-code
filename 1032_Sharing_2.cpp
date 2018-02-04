#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
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
	long int address, next;
	node()
	{
		address = 0,next = 0;
	}
	node(long int add,long int n)
	{
		address = add, next = n;
	}
};

int main()
{
	long int i,first,second,N,tmp1,tmp2;
	string add1,add2,num;
	node *place[MAX];
	char ch;
	int count = 0;
	bool has[MAX];
	bool done=false;
	for(i=0;i<MAX;i++)
		place[i]=NULL,has[i]=false;
	cin>>add1>>add2>>num;
	first = str2lint(add1);
	second = str2lint(add2);
	N = str2lint(num);
	for(i=1;i<=N;i++)
	{
	/*	cin>>add1>>ch>>add2;
		tmp1 = str2lint(add1);
		tmp2 = str2lint(add2);*/
		scanf("%ld %c %ld",&tmp1,&ch,&tmp2);
		node *p;
		if(place[tmp1]==NULL)
		{
			p = new node(tmp1,tmp2);
			place[tmp1]=p;
		}
		else 
		{
			p = place[tmp2];
			p->next=tmp1;
			cout<<tmp2<<endl;
		}
		if(tmp2==-1)
			count++;
	}
	
		tmp1 = first;
		while(tmp1!=-1)
		{
			has[tmp1]=true;
			tmp1 = place[tmp1]->next;
		}
		tmp1 = second;
		while(has[tmp1]==false&&tmp1!=-1)
		{
			has[tmp1]=true;
			tmp1 = place[tmp1]->next;
		}
		if(tmp1!=-1)	 
			printf("%05ld\n",tmp1);
		else
		cout<<-1<<endl;
	
	return 0;
}
