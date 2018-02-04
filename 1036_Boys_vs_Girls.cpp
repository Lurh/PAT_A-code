#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stdio.h>
using namespace std;

struct person{
	string name,course;
	char gender;
	int grade;
	person()
	{
		name="",course="";
		grade = -1;
	}
	person(string na,string co, char gen, int g)
	{
		name = na;
		course = co;
		gender = gen;
		grade = g;
	}
};

bool compare(person p1,person p2)
{
	return p1.grade>p2.grade;
}

int main()
{
	int N,grade;
	string name,course;
	char gen;
	vector<person> male,female;
	cin>>N;
	while(N--)
	{
		//scanf("%s %c %s %d",&name,&gen,&course,&grade);
		cin>>name>>gen>>course>>grade;
		person p(name,course,gen,grade);
		if(gen=='F')
			female.push_back(p);
		else
			male.push_back(p);
	}
	if(!male.empty())
	sort(male.begin(),male.end(),compare);
	if(!female.empty())
	sort(female.begin(),female.end(),compare);
	if(!female.empty())
		cout<<female.at(0).name<<" "<<female.at(0).course<<endl;
	else
		cout<<"Absent"<<endl;
	if(!male.empty())
		cout<<male.at(male.size()-1).name<<" "<<male.at(male.size()-1).course<<endl;
	else
		cout<<"Absent"<<endl;
	if(!female.empty()&&!male.empty())
		cout<<female.at(0).grade-male.at(male.size()-1).grade<<endl;
	else
		cout<<"NA"<<endl;
	return 0;
}
