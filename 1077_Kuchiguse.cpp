#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
using namespace std;

int main()
{
	int N,len,i,j;
	string tmp="",tmp1;
	vector<char> same;
	vector<string> sen;
	scanf("%d ",&N);
	while(N--)
	{
		getline(cin,tmp);
		sen.push_back(tmp);
	}
	tmp=sen.at(0);
	tmp1=sen.at(1);
	for(i=tmp.length()-1,j=tmp1.length()-1;i>=0,j>=0;i--,j--)
		if(tmp[i]==tmp1[j])
			same.push_back(tmp[i]);
		else
			break;
	len = same.size();
	if(sen.size()>=2)
	for(int t=2;t<sen.size();t++)
	{
		tmp = sen.at(t);
		vector<char> same2;
		for(i=0,j=tmp.length()-1;i<same.size()&&j>=0;i++,j--)
			if(same.at(i)==tmp[j])
				same2.push_back(tmp[j]);
			else
				break;
		len = same2.size();
		same = same2;
		if(same.empty())
			break;
	}
	if(same.empty())
		cout<<"nai";
	else
		for(i=same.size()-1;i>=0;i--)
			cout<<same.at(i);
	cout<<endl;
	return 0;
}

