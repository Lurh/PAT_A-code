#include <iostream>
#include <string>
#include <vector>
#define MAX 54
using namespace std;

int main()
{
	int N,i,p;
	vector<string> card;
	vector<int> before,after,move;
	card.push_back("00");
	before.push_back(0);
	move.push_back(0);
	after.push_back(0);
	for(i=0;i<MAX;i++)
	{
		string c;
		if(i%13<9)
			c="S1";
		else
			c="S10";
		if(i<13)
			c[0]='S';
		else if(i<26)
			c[0]='H';
		else if(i<39)
			c[0]='C';
		else if(i<52)
			c[0]='D';
		else
			c[0]='J';
		if(i%13<9)
			c[1]=char(i%13+1)+'0';
		else
			c[1]='1',c[2]=i%13-9+'0';
		card.push_back(c);
		before.push_back(i+1);
		after.push_back(0);
	}
	cin>>N;
	for(i=1;i<=MAX;i++)
	{
		cin>>p;
		move.push_back(p);
	}
	while(N--)
	{
		for(i=1;i<=MAX;i++)
			after.at(move.at(i))=before.at(i);
		before = after;
	}
	cout<<card.at(after.at(1));
	for(i=2;i<=MAX;i++)
		cout<<" "<<card.at(after.at(i));
	cout<<endl;
	return 0;
}
