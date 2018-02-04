#include <iostream>
#include <string>
#include <stdio.h>
#define MAX 36
#define LEN 11
using namespace std;

int main()
{
	//freopen("A.in","r",stdin);
	string N1,N2;
	string num1,num2;
	int tag,rad,i,j,min_rad=0;
	long long src=0;
	char goal[LEN];
	char dig[MAX] = {'0','1','2','3','4','5','6','7','8','9','a',
					'b','c','d','e','f','g','h','i','j','k','l',
					'm','n','o','p','q','r','s','t','u','v','w',
					'x','y','z'};
	cin>>N1>>N2>>tag>>rad;
	if(tag==1)
		num1=N1,num2=N2;
	else
		num1=N2,num2=N1;

	for(i=0;i<num1.length();i++)
		if(num1[i]>='0'&&num1[i]<='9')
			src = src*rad + num1[i]-'0';
		else if(num1[i]>='a'&&num1[i]<='z')
			src = src*rad + num1[i]-'a'+10;
			
	for(i=0;i<num2.length();i++)
		min_rad = (min_rad>num2[i])?min_rad:num2[i];
	if(min_rad>='a')
		min_rad=min_rad-'a'+10;
	else
		min_rad=min_rad-'0';
	if(min_rad==1)
		min_rad++;
		
	int tmp;
	long tmp_src;
	bool equal;
	for(j=min_rad;j<=MAX;j++)
	{
		for(int t=0;t<LEN;t++)
			goal[t]='0';
		tmp_src = src;
		i=0;
		equal=true;
		while(tmp_src>0)
		{
			tmp=tmp_src%j;
			goal[i]=dig[tmp];
			tmp_src = (tmp_src-tmp)/j;
			i++;
		}	
		if(i!=num2.length())
		{
			equal = false;
			continue;
		}
		for(int t=i-1;t>=0;t--)
			if(goal[t]!=num2[num2.length()-t-1])
			{
				equal = false;
				break;
			}
		if(equal)
		{
			cout<<j<<endl;
			break;
		}
	}
	if(equal==false)
		cout<<"Impossible"<<endl;
	return 0;
 } 
