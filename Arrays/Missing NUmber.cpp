//Time: O(N) --> For iteration 
//Space: O(1) --> Constant Space 

class Solution {
public:
    int missingNumber(vector<int>& nums) 
    {
        int n = nums.size();
        
        if(n == 0){ return -1};
        int TotalSum = (n*(n+1)/2); 
        
        int ArraySum = 0; 
        
        for(int i=0; i<nums.size(); i++)
        {
            ArraySum = ArraySum + nums[i];
        }
        
        return TotalSum - ArraySum;
    }
};
