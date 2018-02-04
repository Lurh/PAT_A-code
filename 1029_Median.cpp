#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<long int> q1,q2;
	long int N,tmp,total=0,count=0,now,i,j;
	cin>>N;
	total += N;
	while(N--)
	{
		cin>>tmp;
		q1.push_back(tmp);
	}
	cin>>N;
	total += N;
	while(N--)
	{
		cin>>tmp;
		q2.push_back(tmp);
	}
	if(q1.at(0)<=q2.at(0))
		i=1,j=0,now=q1.at(0);
	else
		i=0,j=1,now=q2.at(0);
	count++;
	while((total+1)/2!=count)
	{
		if(i<q1.size()&&j<q2.size())
			if(q1.at(i)<=q2.at(j))
				now=q1.at(i),i++;
			else
				now=q2.at(j),j++;
		else if(i==q1.size())
			now=q2.at(j),j++;
		else if(j==q2.size())
			now=q1.at(i),i++;
		count++;
	}
	cout<<now<<endl;
	return 0;
} 
