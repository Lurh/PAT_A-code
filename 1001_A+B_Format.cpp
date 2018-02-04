#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	long a,b,sum;
	int i=-1,j=-1;
	char num[10];
	char fin[10];
	cin>>a>>b;
	sum=a+b;
	if(sum<0)
	cout<<"-";
	sum = abs(sum);
	while(true)
	{
		i++;
		j++;
		num[i]=char('0'+sum%10);
		fin[j]=num[i];
		
		if((i+1)%3==0&&sum>=10)
		{
			j++;
			fin[j]=',';
		}
		sum =sum/10;
		if(sum==0)
		break;
	}
	while(j>=0)
	{
		cout<<fin[j];
		j--;
	}
	cout<<endl;
	return 0;
}
