#include <iostream>
#include <vector>
#include <stdio.h>
#define LEN 257
#define MUC 10
using namespace std;

int main()
{
	vector<char> origin,ans,stuck;
	char ch,now='.',tmp;
	int min_ch[LEN],max;
	bool ch_is[LEN],in[LEN];
	int count=0,i,j;
	for(i=0;i<LEN;i++)
		min_ch[i]=65535,ch_is[i]=false,in[i]=false;
	scanf("%d",&max);
	scanf("%c",&tmp);
	while(1)
	{
		scanf("%c",&ch);
		if(ch=='\n')
			break;
		origin.push_back(ch);
		if(now!=ch)
		{
			if(min_ch[now]>count)
				min_ch[now]=count;	
			now = ch;
			count = 1;
		}
		else
		{
			if(count>=max)
				count=1;
			else
				count++;
		}
	}
	for(i=0;i<LEN;i++)
	{
		if(min_ch[i]==max)
		{
			ch_is[i] = true;
		}
	}
	now = '.';
	for(i=0;i<origin.size();i++)
	{
		if(now!=origin.at(i))
		{
			now = origin.at(i);
			count = 1;
		}
		else
		{
			if(count>=max)
				count=1;
			else
				count++;
		}
			
		if(ch_is[now]&&count==1)
			ans.push_back(now);
		else if(ch_is[now]==false)
			ans.push_back(now);
		if(ch_is[now]&&in[now]==false)
		{
			stuck.push_back(now);
			in[now]=true;
		}
	}
	for(i=0;i<stuck.size();i++)
		printf("%c",stuck.at(i));
	printf("\n");
	for(i=0;i<ans.size();i++)
		printf("%c",ans.at(i));
	printf("\n");
	return 0;
} 
