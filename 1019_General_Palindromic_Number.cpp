#include <iostream>
#include <vector>
using namespace std;

vector<long> num2rad(long num,long rad)
{
	vector<long> origin;
	if(num==0)
		origin.push_back(0);
	while(num>0)
	{
		origin.push_back(num%rad);
		num = (num-num%rad)/rad;
	}
	return origin;
}

bool isPalin(vector<long> vec)
{
	bool is = true;
	for(int i=0;i<vec.size();i++)
		if(vec.at(i)!=vec.at(vec.size()-1-i))
		{
			is = false;
			break;
		}
	return is;
}

int main()
{
	long num,rad;
	cin>>num>>rad;
	vector<long> origin;
	origin = num2rad(num,rad);
	if(isPalin(origin))
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
	cout<<origin.at(origin.size()-1);
	if(origin.size()>=2)
		for(int i=origin.size()-2;i>=0;i--)
			cout<<" "<<origin.at(i);
	return 0;
}
