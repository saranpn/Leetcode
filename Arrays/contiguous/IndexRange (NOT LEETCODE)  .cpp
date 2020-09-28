#include <vector> 
#include <iostream>

using namespace std;

pair<int,int> subArrayPair(vector<int> nums, int target)
{
    pair<int, int> IndexRange; 
    int n = nums.size();
    int currSum = 0;
    
    int start = 0;
    
    for(int i=0; i<n; i++)
    {
        currSum = currSum + nums[i];
        
        if(currSum > target)
        {
            currSum = currSum - nums[start];
            start++;
        }
        
        if(currSum == target)
        {
            IndexRange.first = start;
            IndexRange.second = i; 
        }
    }
    
    cout << IndexRange.first << " " << IndexRange.second;
    return IndexRange;
}

int main()
{
    vector<int> nums = {1,2,3,7,5};
    int target = 12;
    
    subArrayPair(nums, target);

    return 0;
}
