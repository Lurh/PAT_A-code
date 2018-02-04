#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#define MAX 10010
using namespace std;

bool isprime(int n)
{
	int i;
	for(i=2;i*i<=n;i++)
	{
		if(n%i==0)
		return false;
	}
	return true;
}

struct person{
	bool visited;
	string award;
	person()
	{
		visited = false;
		award ="";
	}
};

int main()
{
	int N,K,i,id;
	person *contestant[MAX];
	scanf("%d",&N);
	person *p;
	for(i=1;i<=N;i++)
	{
		scanf("%d",&id);
		p = new person();
		if(i==1)
			p->award="Mystery Award";
		else
		{
			if(isprime(i))
				p->award="Minion";
			else
				p->award="Chocolate";
		}
		contestant[id]=p;
	}
	scanf("%d",&K);
	for(i=1;i<=K;i++)
	{
		scanf("%d",&id);
		p = contestant[id];
		if(p==NULL)
		{
			printf("%04d: ",id);
			printf("Are you kidding?\n");
		}
		else if(p->visited)
		{
			printf("%04d: ",id);
			printf("Checked\n");
		}	
		else
		{
			printf("%04d: ",id);
			cout<<p->award<<endl;
			p->visited=true;
		}
	}
	return 0;
}
