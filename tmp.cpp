#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int findDuplicate(vector<int>& nums) {
        int i,j,sum=0,tmp=0,ans=0;
        for(i=0;i<nums.size();i++)
        {
            sum+=i;
            tmp+=nums[i];
        }
        tmp-=sum;
        for(i=max(int(tmp+sum/nums.size()),int(sum/nums.size()));i>=0;i--)
        {
            ans = 0;
            for(j=0;j<nums.size();j++)
                if(nums[j]==i)
                {
                    ans++;
                    if(ans>1)
                        return nums[j];
                }
        }
    }
    
    
int main()
{
	vector<int> ans;
	
	ans.push_back(8);
	ans.push_back(1);
	ans.push_back(1);
	ans.push_back(1);
	ans.push_back(2);
	ans.push_back(7);
	ans.push_back(4);
	ans.push_back(3);
	ans.push_back(1);
	ans.push_back(1);
	cout<<findDuplicate(ans)<<endl;
	return 0;
}
