#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <math.h>
#define MAX 1002
#define WIN 21
#define LEN 11
#define TIM 541
using namespace std;

string num2time(int num1,int num)
{
	if(num1>=TIM-1)
		return "Sorry";
	string time="08:00";
	int h,m;
	m=num%60;
	h=((num-m)/60)%24+8;
	time[0]=h/10+'0';
	time[1]=h%10+'0';
	time[2]=':';
	time[3]=m/10+'0';
	time[4]=m%10+'0';
	return time;
}

struct customer{
	int id,process_time;
	customer(int id,int process_time)
	{
		this->id = id;
		this->process_time = process_time;
	}
};

int main()
{
	int i,j,N,M,K,Q,t,id;
	queue<customer> process_queue[WIN];
	queue<customer> origin_queue;
	int begin_time[MAX],done_time[MAX],queue_time[WIN];
	vector<int> queue_move[TIM+3000];
	for(i=0;i<MAX;i++)
		done_time[i] = 65535;
	for(i=0;i<WIN;i++)
		queue_time[i] = 0;
	cin>>N>>M>>K>>Q;
	for(i=1;i<=K;i++)
	{
		cin>>t;
		customer c(i,t);
		origin_queue.push(c);
	}

	for(i=0;i<M;i++)
		for(j=0;j<N;j++)
			if(!origin_queue.empty())
			{
				process_queue[j].push(origin_queue.front());
				origin_queue.pop();
			}

	for(i=0;i<N;i++)
		for(j=0;j<M;j++)
			if(!process_queue[i].empty())
			{
				begin_time[origin_queue.front().id]=queue_time[i];
				queue_time[i]+=process_queue[i].front().process_time;
				done_time[process_queue[i].front().id]=queue_time[i];
				queue_move[queue_time[i]].push_back(i);
				process_queue[i].pop();
			}

	for(i=0;i<TIM;i++)
		if(!queue_move[i].empty())
			for(j=0;j<queue_move[i].size();j++)
				if(!origin_queue.empty())
				{
					begin_time[origin_queue.front().id]=queue_time[queue_move[i].at(j)];
					queue_time[queue_move[i].at(j)]+=origin_queue.front().process_time;
					done_time[origin_queue.front().id]=queue_time[queue_move[i].at(j)];
					queue_move[queue_time[queue_move[i].at(j)]].push_back(queue_move[i].at(j));
					origin_queue.pop();
				}
		
	for(i=1;i<=Q;i++)
	{
		cin>>id;
		cout<<num2time(begin_time[id],done_time[id])<<endl;
	}
	return 0;
}

