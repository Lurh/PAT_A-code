#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int main()
{
	freopen("B.out","w",stdout);
	int i,j;
	bool is;
	printf("2,");
	for(i=3;i<10000;i+=2)
	{
		is = true;
		for(j=2;j*j<=i;j++)
		{
			if(i%j==0)
			{
				is = false;
				break;
			}
		}
		if(is)
		printf("%d,",i);
	}
	printf("\n");
	return 0;
 } 
