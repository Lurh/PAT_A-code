#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	string str;
	vector<char> ans;
	int i,j;
	cin>>str;

	for(i=1;i<str.size();i++)
		if(str[i]!='E')
			ans.push_back(str[i]);
		else
			break;
	
	int exp=0,num=i-2;
	bool exp_negative=str[i+1]=='-'?true:false;
	for(i=num+4;i<str.size();i++)
		exp = exp*10+str[i]-'0';
	if(exp_negative==false)
	{
		if(num<=exp)
		{
			int tmp = exp-num;
			tmp++;
			while(tmp--)
				ans.push_back('0');
			ans.erase(ans.begin()+1);
		}
		else if(num==exp+1)
		{
			ans.erase(ans.begin()+1);
		}
		else if(exp!=0)
		{
			vector <char>::iterator start = ans.begin()+1;
			int tmp = exp;
			i=1;
			while(tmp--)
			{
				swap(ans[i],ans[i+1]);
				i++;
			}
		}
	}	
	else
	{
		int tmp = exp;
		while(tmp--)
		{
			swap(ans[0],ans[1]);
			vector <char>::iterator start = ans.begin();
			ans.insert(start,'0');
		}
	}
	vector <char>::iterator start = ans.begin();
	if(str[0]=='-')
		ans.insert(start,'-');
	for(i=0;i<ans.size();i++)
		cout<<ans[i];
	cout<<endl;
	return 0;
}
