#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, tmp=0, i, max = -1, sum = 0, left = 0, right = 0;
    bool is=false;
    vector<int> seq;
    scanf("%d",&n);
    for(i = 0;i < n;i++)
    {
        scanf("%d",&tmp);
        seq.push_back(tmp);
    }
    tmp = 0;
    for(i = 0;i < n;i++)
    {
    	if(is)
    	{
    		tmp = i;
    		is = false;
		}	
        sum += seq[i];
        if(sum < 0)
        {
        	sum = 0;
        	is = true;
		}
        else if(sum > max)
        {
        	max = sum;
        	left = tmp;
        	right = i;
		}      
    }
    if(max >= 0)
    	printf("%d %d %d", max, seq[left], seq[right]);
    else
    	printf("%d %d %d", 0, seq[0], seq[n-1]);
    return 0;
}
