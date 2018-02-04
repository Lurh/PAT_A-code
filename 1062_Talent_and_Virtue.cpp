#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <cstring>
#define LEN 8
using namespace std;

struct person{
	string id;
	int talent,virtue;
	person()
	{
		talent = 0;
		virtue = 0;
	}
	person(char ch[],int t,int v)
	{
		id = ch;
		talent = t;
		virtue = v;
	}
};

bool compare(person p1,person p2)
{
	if(p1.talent+p1.virtue>p2.talent+p2.virtue)
		return true;
	else if(p1.talent+p1.virtue==p2.talent+p2.virtue)
		if(p1.virtue>p2.virtue)
			return true;
		else if(p1.virtue==p2.virtue)
			return p1.id>p2.id;
	return false;
}

int main()
{
	int N,L,H,i;
	int count = 0;
	vector<person> sages,noble,fool,small;
	scanf("%d%d%d",&N,&L,&H);
	for(i=1;i<=N;i++)
	{
		int tmp_t,tmp_v;
		char ch[LEN];
		scanf("%s %d %d",ch,&tmp_t,&tmp_v);
		if(min(tmp_t,tmp_v)>=L)
		{
			count++;
			person p(ch,tmp_t,tmp_v);
			if(min(tmp_t,tmp_v)>=H)
				sages.push_back(p);
			else if(tmp_t<H&&tmp_v>=H)
				noble.push_back(p);
			else if(tmp_v>=tmp_t)
				fool.push_back(p);
			else
				small.push_back(p);
		}
	}
	sort(sages.begin(),sages.end(),compare);
	sort(noble.begin(),noble.end(),compare);
	sort(fool.begin(),fool.end(),compare);
	sort(small.begin(),small.end(),compare);
	printf("%d\n",count);
	cout<<sages.size()<<" "<<noble.size()<<" "<<fool.size()<<" "<<small.size()<<endl;
	cout<<sages.at(0).id<<endl;
	for(i=0;i<sages.size();i++);
		cout<<sages.at(i).id<<" "<<sages.at(i).talent<<" "<<sages.at(i).virtue<<endl;
		//printf("%s %d %d\n",sages.at(i).id,sages.at(i).talent,sages.at(i).virtue);
	for(i=0;i<noble.size();i++);
		cout<<noble.at(i).id<<" "<<noble.at(i).talent<<" "<<noble.at(i).virtue<<endl;
		//printf("%s %d %d\n",noble.at(i).id,noble.at(i).talent,noble.at(i).virtue);
	for(i=0;i<fool.size();i++);
		cout<<fool.at(i).id<<" "<<fool.at(i).talent<<" "<<fool.at(i).virtue<<endl;
		//printf("%s %d %d\n",fool.at(i).id,fool.at(i).talent,fool.at(i).virtue);
	for(i=0;i<small.size();i++);
		cout<<small.at(i).id<<" "<<small.at(i).talent<<" "<<small.at(i).virtue<<endl;
		//printf("%s %d %d\n",small.at(i).id,small.at(i).talent,small.at(i).virtue);
	
	return 0;
}

