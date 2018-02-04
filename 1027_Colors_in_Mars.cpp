#include <iostream>
#include <string>
using namespace std;

string num2rad(int num)
{
	string rad="00";
	char ch[13]={'0','1','2','3','4','5','6','7','8','9','A','B','C'};
	int t,o;
	o = num%13;
	t = (num-o)/13;
	rad[0]=ch[t];
	rad[1]=ch[o];
	return rad;
}

int main()
{
	int R,G,B;
	cin>>R>>G>>B;
	cout<<'#'<<num2rad(R)<<num2rad(G)<<num2rad(B)<<endl;
	return 0;
}
