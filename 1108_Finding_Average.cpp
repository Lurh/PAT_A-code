#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
//计算和判断分开，计算字符串的值 sscanf(s.c_str(),"%ld",&ans); 
bool isLegal(string s)
{
	int pos = 0;
	if(s[pos] == '-' ) pos++;
	if(pos == s.length()) return false;
	int dotcnt = 0;
	for(int i = pos; i < s.length(); i++)
	{
		if(s[i] == '.')
		{
			dotcnt++;
			if(dotcnt > 1) return false;
			if(s.length() - i - 1 > 2) return false;
		}
		else if(s[i] < '0' || s[i] > '9')
			return false;
	}
	double d;
	sscanf(s.c_str(), "%lf", &d);
	if(d > 1000.0 || d < -1000.0) return false;
	else return true;
}

int main(){
	int n;
	cin>>n;
	double sum = 0.0;
	int cnt = 0;
	for(int i = 0; i < n; i++)
	{
		string s;
		cin>>s;
		if(isLegal(s))
		{
			double d;
			sscanf(s.c_str(), "%lf", &d);
			cnt++;
			sum += d;
		}
		else
		{
			printf("ERROR: ");
			cout<<s;
			printf(" is not a legal number\n");
		}
	}

	if(cnt == 0)
	{
		printf("The average of 0 numbers is Undefined\n");
	}
	else if(cnt == 1)
		printf("The average of 1 number is %.2lf\n",sum);
	else
		printf("The average of %d numbers is %.2lf\n",cnt,sum/cnt);
	return 0;
}
