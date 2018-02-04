#include <iostream>
#include <string>
#define MAX 1001
#define COLOR 201
using namespace std;

int main()
{
	string shop,eva;
	int i;
	int has[COLOR],need[COLOR];
	for(i=0;i<COLOR;i++)
		has[i]=0,need[i]=0;
	cin>>shop>>eva;
	for(i=0;i<shop.length();i++)
		has[shop[i]]++;
	for(i=0;i<eva.length();i++)
		need[eva[i]]++;
	bool can=true;
	for(i=0;i<COLOR;i++)
		if(need[i]>has[i])
		{
			can=false;
			break;
		}
	int extra=0,missing=0;
	if(can)
	{
		for(i=0;i<COLOR;i++)
			extra+=has[i]-need[i];
		cout<<"Yes "<<extra<<endl; 
	}	
	else
	{
		for(i=0;i<COLOR;i++)
			if(need[i]>0&&has[i]<need[i])
				missing+=need[i]-has[i];
		cout<<"No "<<missing<<endl;
	} 
		
	return 0;
}

 
