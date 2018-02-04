#include <iostream>
#include <stdio.h>
#define MAX 1000000007
using namespace std;

int main()
{
	long sum=0,count=0,total=0;
	bool begin = false;
	char tmp;
	while(scanf("%c",&tmp))
	{
		if(tmp=='\n')
		break;
		if(begin==false)
		{
			if(tmp=='P')
				begin = true;
			else
				continue;
		}
		if(tmp=='P')
			count++;
		else if(tmp=='A')
			total+=count;
		else if(tmp=='T')
			sum = (sum+total)%MAX;
	}
	printf("%ld\n",sum);
	return 0;
}
