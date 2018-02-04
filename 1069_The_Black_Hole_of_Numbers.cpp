#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	int num1,num2,result=1,tmp;
	int str_int[4];
	cin>>num1;
	while(result!=6174&&result!=0)
	{
		tmp = num1;
		for(int i=0;i<4;i++)
		{
			str_int[i]=tmp%10;
			tmp = tmp/10;
		}
		sort(str_int,str_int+4);
		num1 = str_int[3]*1000+str_int[2]*100+str_int[1]*10+str_int[0];
		num2 = str_int[0]*1000+str_int[1]*100+str_int[2]*10+str_int[3];
		result=num1-num2;
		printf("%04d - %04d = %04d\n",num1,num2,result);
		num1 = result;
	}
	return 0;
 } 
