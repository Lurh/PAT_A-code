#include <iostream>
#include <string>
#include <math.h>
#define MAX 28
using namespace std;

int main()
{
	string str;
	int i,j,len,left,right,n1,n2;
	char mtrx[MAX][MAX];
	cin>>str;
	len = str.length();
	left = 0;
	right = len-1;
	n1=1;n2=len+2-2*n1;
	while(n2-2>=n1+1)
	{
		n1++;
		n2=len+2-2*n1;
	}	
	for(i=0;i<n1;i++)
	{
		for(j=0;j<n2;j++)
		{
			if(i!=n1-1)
			{
				if(j==0)
				{
					mtrx[i][j]=str[left];
					left++;
				}
				else if(j==n2-1)
				{
					mtrx[i][j]=str[right];
					right--;
				}
				else
					mtrx[i][j]=' ';		
			}
			else
			{
				mtrx[i][j]=str[left];
				left++;
			}
		}
	}
	for(i=0;i<n1;i++)
	{
		for(j=0;j<n2;j++)
			cout<<mtrx[i][j];
		cout<<endl;
	}
	return 0;
}
