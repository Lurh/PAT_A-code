#include <iostream>
#include <string>
#include <vector>
#define MAX 86401
using namespace std;

int time2num(string time)
{
	int h,m,s;
	h = (time[0]-'0')*10+time[1]-'0';
	m = (time[3]-'0')*10+time[4]-'0';
	s = (time[6]-'0')*10+time[7]-'0';
	return h*3600+m*60+s;
}

int main()
{
	int M,i;
	vector<string> person;
	string ID,arrive_time,leave_time;
	int time_stamp[MAX];
	for(i=0;i<MAX;i++)
		time_stamp[i]=-1;
	cin>>M;
	for(i=0;i<M;i++)
	{
		cin>>ID>>arrive_time>>leave_time;
		person.push_back(ID);
		time_stamp[time2num(arrive_time)]=i;
		time_stamp[time2num(leave_time)]=i;
	}
	for(i=0;i<MAX;i++)
		if(time_stamp[i]!=-1)
		{
			cout<<person.at(time_stamp[i]);
			break;
		}
		
	for(i=MAX-1;i>=0;i--)
		if(time_stamp[i]!=-1)
		{
			cout<<" "<<person.at(time_stamp[i]);
			break;
		}
	return 0;
}
