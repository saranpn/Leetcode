// USING MAX HEAP 

#include <iostream>
#include <vector> 
#include <algorithm>
#include <queue>

using namespace std;

int KthSmallestNumber(vector<int> nums, int k, int result)
{
    priority_queue<int> Q;
    
    int n = nums.size();
    
    for(int i=0; i<k; i++)
    {
        Q.push(nums[i]);
    }
    
    for(int i=k; i<n; i++)
    {
        if(Q.top()>nums[i])
        {
            Q.pop();
            Q.push(nums[i]);
        }
    }
    
    return Q.top();
}

int main()
{
    vector<int> nums = {10,50,40,30,20};
    int k = 4;
    int result = 0;
    result = KthSmallestNumber(nums,k, result);
    cout << result;
    return 0;
}
