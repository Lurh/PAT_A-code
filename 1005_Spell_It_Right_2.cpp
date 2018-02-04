#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <math.h>
#define MAX 101
using namespace std;

int main()
{
	string input;
	int N,i,sum=0;
	stack<int> num;
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
		
	cin>>input;
	N = input.length();
	for(i=0;i<N;i++)
		sum+=input[i]-'0';
	while(sum>=10)
	{
		num.push(sum%10);
		sum=(sum-sum%10)/10;
	}
	cout<<num_str.at(sum);	
	while(!num.empty())
	{
		cout<<" "<<num_str.at(num.top());
		num.pop();
	}
	cout<<endl;
	
	return 0;
}
