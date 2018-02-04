#include <iostream>
#include <string>
#include <queue>
#define MAX 10001
#define LEN 501
using namespace std;

int main()
{
	int i;
	string str,ch;
	queue<char> ans;
	while(!ans.empty())
		ans.pop();
	bool has[LEN];
	for(i=0;i<LEN;i++)
		has[i]=true;
	getline(cin,str);
	getline(cin,ch);
	for(i=0;i<ch.length();i++)
		if(ch[i]>='a'&&ch[i]<='z')
			has[ch[i]]=false,has[ch[i]-32]=false;
		else if(ch[i]>='A'&&ch[i]<='Z')
			has[ch[i]]=false,has[ch[i]+32]=false;
		else
			has[ch[i]]=false;
	for(i=0;i<str.length();i++)
		if(has[str[i]])
			cout<<str[i];
	
	return 0;
 } 
