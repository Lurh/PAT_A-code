#include <iostream>
using namespace std;

int main()
{
	int s1,k1,s2,k2;
	long g1,g2;
	char ch1,ch2;
	cin>>g1>>ch1>>s1>>ch2>>k1;
	cin>>g2>>ch1>>s2>>ch2>>k2;
	k1 = k1+k2;
	s1 = s1+s2+k1/29;
	k1 = k1%29;
	g1 = g1+g2+s1/17;
	s1 = s1%17;
	cout<<g1<<'.'<<s1<<'.'<<k1<<endl;
}
