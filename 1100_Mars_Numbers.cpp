#include <iostream>
#include <stdio.h>
#include <cstring>
#include <stack>
#define LEN 13
using namespace std;

int main()
{
	string low[LEN]={"tret","jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec"};
	string up[LEN]={"tret","tam","hel","maa","huh","tou","kes","hei","elo","syy","lok","mer","jou"};
	int N,i,j;
	bool is_earth=false;
	stack<string> ans1;
	scanf("%d",&N);
	string tmp;
	for(i=1;i<=N;i++)
	{
		cin>>tmp;
		is_earth=false;
		if(tmp[0]>='0'&&tmp[0]<='9')
			is_earth=true;
		if(is_earth)
		{
			int num=0;
			for(j=0;j<tmp.size();j++)
				num = num*10+tmp[j]-'0';
			bool has=false;
			while(num>0)
			{
				if(has==false)
				{
					if(num%LEN!=0)
						ans1.push(low[num%LEN]);
				}		
				else
					ans1.push(up[num%LEN]);
				has = true;
				num=num/LEN;
			}
			if(ans1.empty())
				ans1.push(low[0]);
			cout<<ans1.top();
			ans1.pop();
			while(!ans1.empty())
			{
				cout<<" "<<ans1.top();
				ans1.pop();
			}
			cout<<endl;
		}
		else
		{
			int num=0;
			for(j=0;j<LEN;j++)
			{
				if(tmp==up[j])
				{
					num+=j*13;
					break;
				}
			}
			char ch;
			scanf("%c",&ch);
			if(ch!='\n')
			{
				cin>>tmp;
				for(j=0;j<LEN;j++)
				{
					if(tmp==up[j])
					{
						num+=j*13;
						break;
					}	
					if(tmp==low[j])
					{
						num+=j;
						break;
					}			
				}
			}
			cout<<num<<endl;
		}
	}
	return 0;
}
