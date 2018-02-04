#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#define MAX 100010
using namespace std;

struct node{
	long int address,num,next;
	node(int add,int n,int ne)
	{
		address = add, num = n, next = ne;
	}
};

bool cmp(node* n1,node* n2)
{
	if(n1->num<n2->num)
		return true;
	else if(n1->num>n2->num)
		return false;
	else
		return n1->address<n2->address;
}
int main()
{
	int N,i;
	long int id,num,next,head;
	node* original[MAX];
	for(i=0;i<MAX;i++)
		original[i]=NULL;
	vector<node*> list;
	node *tmp;
	scanf("%d%ld",&N,&head);
	for(i=1;i<=N;i++)
	{
		scanf("%ld%ld%ld",&id,&num,&next);
		tmp = new node(id,num,next);
		original[id] = tmp;
	}
	while(head!=-1)
	{
		list.push_back(original[head]);
		head = original[head]->next;
	}
	sort(list.begin(),list.end(),cmp);
	if(!list.empty())
		printf("%d %05ld\n",list.size(),list.at(0)->address);
	else
		printf("0 -1\n");
	for(i=0;i<list.size();i++)
		if(i!=list.size()-1)
			printf("%05ld %ld %05ld\n",list.at(i)->address,list.at(i)->num,list.at(i+1)->address);
		else
			printf("%05ld %ld -1\n",list.at(i)->address,list.at(i)->num);
	return 0;
}
