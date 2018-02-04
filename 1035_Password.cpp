#include <iostream>
#include <string>
#include <vector>
#define MAX 1002
using namespace std;

int main()
{
	int N,i,j,sum=0;
	vector<string> user,password;
	string u,p;
	bool mdf[MAX];
	for(i=0;i<MAX;i++)
		mdf[i]=false;
	cin>>N;
	for(i=0;i<N;i++)
	{
		cin>>u>>p;
		user.push_back(u);
		password.push_back(p);
		for(j=0;j<p.length();j++)
			if(p[j]=='1'||p[j]=='l'||p[j]=='0'||p[j]=='O')
			{
				mdf[i]=true;
				sum++;
				break;
			}
	}
	if(sum==0||N==1)
		if(N>1)
			cout<<"There are "<<N<<" accounts and no account is modified"<<endl;
		else
			cout<<"There is "<<N<<" account and no account is modified"<<endl;
	else
	{
		cout<<sum<<endl;
		for(i=0;i<N;i++)
			if(mdf[i])
			{
				cout<<user.at(i)<<" ";
				p=password.at(i);
				for(j=0;j<p.length();j++)
				{
					if(p[j]=='1')
						cout<<'@';
					else if(p[j]=='l')
						cout<<'L';
					else if(p[j]=='0')
						cout<<'%';
					else if(p[j]=='O')
						cout<<'o';
					else
						cout<<p[j];
				}
				cout<<endl;
			}
	}
	return 0;	
} 
