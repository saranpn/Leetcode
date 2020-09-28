//All Test Cases are Not passing

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        int n = nums.size();
        
        vector<int> result; 
        
        if(n==1 && nums[0] == target)
        {
            result.push_back(0);
            result.push_back(0);
            return result;
        }
        
        for(int i=0; i<n; i++)
        {
            if(nums[i] == target && nums[i+1] != target) //last position 
            {
                result.push_back(i);
            }
            else if(nums[i] == target && nums[i-1] == target && nums[i+1] == target) //middle position 
            {
                continue;
            }
            else if(nums[i] == target) //starting position 
            {
                result.push_back(i);
            }
        }
        
        if(result.size() == 0) 
        {
            result.push_back(-1);
            result.push_back(-1);
        }
        
        return result; 
    }
};
