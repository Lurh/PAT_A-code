#include <iostream>
#include <string>
#include <vector> 
using namespace std;

string toCap(string str)
{
	int i;
	for(i=0;i<str.length();i++)
		if(str[i]>='a'&&str[i]<='z')
			str[i]-=32;
	return str;
}

int main()
{
	string ori,now;
	int i,j;
	cin>>ori>>now;
	ori = toCap(ori);
	now = toCap(now);
	vector<char> broke;
	bool has=true;
	for(i=0;i<ori.length();i++)
	{
		has = true;
		for(j=0;j<now.length();j++)
			if(ori[i]==now[j])
				has = false;
		if(has)
		{
			has = false;
			for(j=0;j<broke.size();j++)
				if(ori[i]==broke.at(j))
				{
					has = true;
					break;
				}
			if(has==false)
				broke.push_back(ori[i]);		
		}
	}
	for(i=0;i<broke.size();i++)
		cout<<broke.at(i);
	cout<<endl;
	return 0;
 } 
