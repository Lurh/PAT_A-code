#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <iomanip>
using namespace std;

struct station{
	double price;
	int length;
};

bool cmp(station *s1, station *s2)
{
	if(s1->length > s2->length)
		return false;
	return true;
}
int main()
{
	int C_max, D, D_avg, N, l, i, j;
	float p, sum = 0, tmp_now, now = 0;
	vector<station*> stats;
	vector<float> gap;
	station *s;
	scanf("%d%d%d%d", &C_max, &D, &D_avg, &N);
	for(i = 1; i <= N; i++)
	{
		scanf("%f%d", &p, &l);
		if(l<=D)
		{
			s = new station;
			s->price = p;
			s->length = l;
			stats.push_back(s); 
		}
	}
	int total = D/D_avg;
	if(total > N*C_max)
	{
		cout<<"The maximum travel distance = "<<setprecision(2)<<double(N*C_max*D_avg)<<endl;
		return 0;
	}
	sort(stats.begin(),stats.end(),cmp);
	if(stats[0]->length!=0)
	{
		cout<<"The maximum travel distance = 0.00"<<endl;
		return 0;
	}
	for(i = 1; i < N; i++)
		gap.push_back(float(stats[i]->length - stats[i-1]->length)/D_avg);
	gap.push_back(float(D - stats[i-1]->length)/D_avg);
	for(i = 0; i < N; i++)
	{
		if(now < gap[i])
		{
			sum += (gap[i] - now)*stats[i]->price;
			now = gap[i];
		}
		j = i;
		while(stats[j]->price > stats[i]->price && j<N)
			j++;
		tmp_now = now - gap[i];
		for(int k = i + 1; k < j&&now < C_max; k++)
		{
			tmp_now -= gap[k];
			if(tmp_now < 0)
			{
				now -= tmp_now;
				sum -= tmp_now*stats[i]->price;
				tmp_now = 0;
			}
		}
		now-=gap[i];
	}
	cout<<setprecision(2)<<sum<<endl;
	return 0;
}
