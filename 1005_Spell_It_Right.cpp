#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#define MAX 101
using namespace std;

int num[MAX];
int ans[MAX];
int N,M=101;
void str2num(string str)
{
	for(int i=0;i<N;i++)
		num[i]=str[i]-'0';
}

void addup()
{
	int i,now;
	for(i=0;i<N;i++)
	{
		ans[MAX-1]+=num[i];
		now=MAX-1;
		while(ans[now]>=10)
		{
			ans[now]=ans[now]%10;
			ans[now-1]++;
			now--;
		}
		M=min(M,now);
	}
}

int main()
{
	string input;
	vector<string> num_str;
	num_str.push_back("zero");
	num_str.push_back("one");
	num_str.push_back("two");
	num_str.push_back("three");
	num_str.push_back("four");
	num_str.push_back("five");
	num_str.push_back("six");
	num_str.push_back("seven");
	num_str.push_back("eight");
	num_str.push_back("nine");
	int i;
	for(i=0;i<MAX;i++)
	{
		ans[i]=0;
		num[i]=0;
	}
		
	cin>>input;
	N = input.length();
	str2num(input);
	addup();
	cout<<num_str.at(ans[M]);
	for(i=M+1;i<=MAX-1;i++)
		cout<<" "<<num_str.at(ans[i]);
	cout<<endl;
	
	return 0;
}
