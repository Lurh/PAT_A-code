#include <iostream>
#include <string>
#include <math.h>
#include <stdio.h>
using namespace std;
// ×¢ÒâÅÐ¶ÏµÄ×Ö·û·¶Î§ 
int main()
{
	char day,hr;
	int m,i,j,count=0;
	string weekday[7] = {"MON","TUE","WED","THU","FRI","SAT","SUN"};
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	for(i=0;i<s1.length();i++)
		if(count==0)
		{
			if(s1[i]==s2[i]&&(s1[i]>='A'&&s1[i]<='G'))
			{
				day = s1[i];
				count++;
			}	
		}		
		else if(count==1)
		{
			if(s1[i]==s2[i]&&((s1[i]>='A'&&s1[i]<='N')||(s1[i]>='0'&&s1[i]<='9')))
			{
				hr = s1[i];
				count++;
				break;
			}	
		}
			
	for(i=0;i<min(s3.length(),s4.length());i++)
		if(s3[i]==s4[i]&&((s3[i]>='a'&&s3[i]<='z')||(s3[i]>='A'&&s3[i]<='Z')))
		{
			m = i;
			break;
		}
	cout<<weekday[day-'A']<<" ";
	if(hr>='0'&&hr<='9')
		cout<<0<<int(hr-'0')<<':';
	else
		cout<<int(hr-'A'+10)<<':';
	printf("%02d",m);
	cout<<endl;
	return 0;			
}
