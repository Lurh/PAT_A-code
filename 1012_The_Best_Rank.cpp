#include <iostream>
#include <string>
#include <vector>
#include <math.h> 
#define MAX 2001
#define MARK 102
using namespace std;

int main()
{
	int i,j,N,M,tmp_c,tmp_m,tmp_e;
	int num=-1,rank_c[MAX],rank_m[MAX],rank_e[MAX],rank_a[MAX];
	bool has_id=false;
	string tmp_id;
	vector<string> ID;
	vector<int> C_queue[MARK];
	vector<int> M_queue[MARK];
	vector<int> E_queue[MARK];
	vector<int> A_queue[MARK];
	cin>>N>>M;
	for(i=0;i<N;i++)
	{
		cin>>tmp_id>>tmp_c>>tmp_m>>tmp_e;
		ID.push_back(tmp_id);
		C_queue[tmp_c].push_back(i);
		M_queue[tmp_m].push_back(i);
		E_queue[tmp_e].push_back(i);
		A_queue[(tmp_c+tmp_m+tmp_e)/3].push_back(i);
	}
	int rank=0;
	for(i=100;i>=0;i--)
	{
		if(!C_queue[i].empty())
		{
			for(j=0;j<C_queue[i].size();j++)
				rank_c[C_queue[i].at(j)]=rank+1;
			rank+=C_queue[i].size();
		}
	}
	rank=0;
	for(i=100;i>=0;i--)
	{
		if(!M_queue[i].empty())
		{
			for(j=0;j<M_queue[i].size();j++)
				rank_m[M_queue[i].at(j)]=rank+1;
			rank+=M_queue[i].size();
		}
	}
	rank=0;
	for(i=100;i>=0;i--)
	{
		if(!E_queue[i].empty())
		{
			for(j=0;j<E_queue[i].size();j++)
				rank_e[E_queue[i].at(j)]=rank+1;
			rank+=E_queue[i].size();
		}
	}
	rank=0;
	for(i=100;i>=0;i--)
	{
		if(!A_queue[i].empty())
		{
			for(j=0;j<A_queue[i].size();j++)
				rank_a[A_queue[i].at(j)]=rank+1;
			rank+=A_queue[i].size();
		}
	}
	
	for(i=1;i<=M;i++)
	{
		cin>>tmp_id;
		has_id = false;
		for(j=0;j<N;j++)
			if(ID.at(j)==tmp_id)
				num=j,has_id=true;
		if(has_id)
		{
			if(rank_a[num]<=rank_c[num]&&rank_a[num]<=rank_m[num]&&rank_a[num]<=rank_e[num])
				cout<<rank_a[num]<<" "<<"A"<<endl;
			else if(rank_c[num]<=rank_a[num]&&rank_c[num]<=rank_m[num]&&rank_c[num]<=rank_e[num])
				cout<<rank_c[num]<<" "<<"C"<<endl;
			else if(rank_m[num]<=rank_a[num]&&rank_m[num]<=rank_c[num]&&rank_m[num]<=rank_e[num])
				cout<<rank_m[num]<<" "<<"M"<<endl;
			else if(rank_e[num]<=rank_a[num]&&rank_e[num]<=rank_m[num]&&rank_e[num]<=rank_c[num])
				cout<<rank_e[num]<<" "<<"E"<<endl;
		}
		else
			cout<<"N/A"<<endl;
	}
	
	return 0;
}	

