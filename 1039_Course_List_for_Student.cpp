#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <stdio.h>
#include <algorithm>
using namespace std;
const long int MAX = 26*26*26*10+1;
struct person{
	string name;
	int count;
	vector<int> course;
	person()
	{
		name = "";
		count = 0;
	}
	person(string n,int co)
	{
		name = n;
		course.push_back(co);
		count = 1;
	}
};

int hashing(string name)
{
	return ((name[0]-'A'+1)*26*26*10+(name[1]-'A'+1)*26*10+(name[2]-'A'+1)*10+(name[3]-'0'+1))%MAX;
}
vector<person> hash_map[MAX];
int main()
{
	int N,K,i,j,course_id,num,place;
	string id;
	
	vector<int> tmp;
	scanf("%d%d",&N,&K);
	//cin>>N>>K;
	for(i=1;i<=K;i++)
	{
		scanf("%d%d",&course_id,&num);
		//cin>>course_id>>num;
		for(j=1;j<=num;j++)
		{
			cin>>id;
			place = hashing(id);
			if(hash_map[place].empty())
			{
				person p(id,course_id);
				hash_map[place].push_back(p);
			}
			else
			{
				bool has = false;
				for(int t=0;t<hash_map[place].size();t++)
				{
					if(hash_map[place].at(t).name==id)
					{
						has = true;
						hash_map[place].at(t).course.push_back(course_id);
						hash_map[place].at(t).count++;
						break;
					}
				}
				if(!has)
				{
					person p(id,course_id);
					hash_map[place].push_back(p);
				}	
			}
		}
	}
	for(i=1;i<=N;i++)
	{
		cin>>id;
		place = hashing(id);
		bool has= false;
		for(j=0;j<hash_map[place].size();j++)
		{
			if(hash_map[place].at(j).name==id)
			{
				cout<<id<<" "<<hash_map[place].at(j).count;
				tmp = hash_map[place].at(j).course;
				sort(tmp.begin(),tmp.end());
				for(int t=0;t<tmp.size();t++)
				{
					//printf(" %d",tmp.at(t));
					cout<<" "<<tmp.at(t);
				}
				cout<<endl;
				has = true;
			}
		}
		if(!has)
		{
			cout<<id<<" "<<0<<endl;
		}
	}
	return 0;
}
