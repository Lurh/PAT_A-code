#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	int K,i,j;
	bool is=true;
	string ori;
	vector<int> num1,num2;
	cin>>ori>>K;
	for(i=0;i<ori.length();i++)
		num1.push_back(ori[i]-'0');
	for(i=0;i<(ori.length()+1)/2;i++)
		if(ori[i]!=ori[ori.length()-1-i])
		{
			is = false;
			break;
		}
	if(is)
	{
		cout<<ori<<endl;
		cout<<0<<endl;
		return 0;
	}
	vector<int> tmp;
	for(i=1;i<=K;i++)
	{
		for(j=num1.size()-1;j>=0;j--)
			num2.push_back(num1.at(j));
		tmp.clear();
		for(j=0;j<num1.size();j++)
		{
			tmp.push_back(num1.at(j)+num2.at(j));
			if(j>=1&&tmp.at(j-1)>=10)
			{
				tmp.at(j-1)%=10;
				tmp.at(j)++;
			}
		}
		if(tmp.back()>=10)
		{
			tmp.back()%=10;
			tmp.push_back(1);
		}
		num1 = tmp;
		is = true;
		for(j=0;j<(num1.size()+1)/2;j++)
			if(num1.at(j)!=num1.at(num1.size()-1-j))
			{
				is = false;
				break;
			}
		if(is||i==K)
		{
			for(j=num1.size()-1;j>=0;j--)
				cout<<num1.at(j);
			cout<<endl;
			cout<<i<<endl;
			return 0;
		}
		num2.clear();
	}
	
}
