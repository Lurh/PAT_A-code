#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	string num;
	vector<int> doubl;
	int ori[11],dou[11],i,tmp;
	for(i=0;i<11;i++)
		ori[i]=0,dou[i]=0;
	cin>>num;
	for(i=0;i<num.length();i++)
		num[i]=num[i]-'0',ori[num[i]]++;
	for(i=num.length()-1;i>=0;i--)
	{
		if(!doubl.empty())
		{
			tmp = num.at(i)*2+doubl.at(num.length()-2-i)/10;
			doubl.at(num.length()-2-i) %=10;
			doubl.push_back(tmp);
		}
		else
			doubl.push_back(num.at(i)*2);
	}
	for(i=0;i<doubl.size();i++)
		dou[doubl.at(i)]++;
	bool is = true;
	for(i=0;i<11;i++)
		if(ori[i]!=dou[i])
		{
			is = false;
			break;
		}	
	if(is)
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
	for(i=doubl.size()-1;i>=0;i--)
		cout<<doubl.at(i);
	return 0;
}
