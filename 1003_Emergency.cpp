#include <iostream>
#define MAX 501
#include <queue>
#include <math.h>
using namespace std;

int N,M,C1,C2;
int team_num[MAX],road_len[MAX][MAX],map[MAX][MAX],connect[MAX];
bool has_visit[MAX];
int max_num,min_len,len_sum,num_sum,count_road;

void dfs(int city)
{
	int i,j;
	if(city==C2)
	{
		//cout<<len_sum<<" "<<num_sum<<endl;
		if(len_sum<min_len)
		{
			min_len=len_sum;
			count_road=1;
			max_num=num_sum;
		}
		else if(len_sum==min_len)
		{
			count_road++;
			max_num=max(num_sum,max_num);
		}
		return;
	}
	for(i=0;i<=connect[city];i++)
	{
		if(has_visit[map[city][i]]==false)
		{
			//cout<<city<<"->"<<map[city][i]<<endl;
			has_visit[map[city][i]]=true;
			len_sum+=road_len[city][map[city][i]];
			num_sum+=team_num[map[city][i]];
			dfs(map[city][i]);
			num_sum-=team_num[map[city][i]];
			len_sum-=road_len[city][map[city][i]];
			has_visit[map[city][i]]=false;
		}
	}
	return;
}

int main()
{
	int i,j,tmp1,tmp2;
	max_num=0;
	min_len=65535;
	len_sum=0;
	num_sum=0;
	count_road=0;
	for(i=0;i<MAX;i++)
	{
		team_num[i]=0;
		connect[i]=-1;
		has_visit[i]=false;
		for(j=0;j<MAX;j++)
			road_len[i][j]=0;
	}
		
	cin>>N>>M>>C1>>C2;
	for(i=0;i<N;i++)
		cin>>team_num[i];
	for(i=1;i<=M;i++)
	{
		cin>>tmp1>>tmp2;
		connect[tmp1]++;
		connect[tmp2]++;
		map[tmp1][connect[tmp1]]=tmp2;
		map[tmp2][connect[tmp2]]=tmp1;
		cin>>road_len[tmp1][tmp2];
		road_len[tmp2][tmp1] = road_len[tmp1][tmp2];
	}
	/*
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
			cout<<map[i][j]<<" ";
		cout<<endl;
	}
	*/	
		
	num_sum+=team_num[C1];
	has_visit[C1]=true;
	dfs(C1);
	cout<<count_road<<" "<<max_num<<endl;
	return 0;
}
