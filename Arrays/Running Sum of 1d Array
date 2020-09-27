class Solution {
public:
    vector<int> runningSum(vector<int>& nums) 
    {
        int n = nums.size();
        
        if(n==0) return {};

        vector<int> result(n,0); 

        result[0] = nums[0];

        for(int i=1; i<n; i++)
        {
            result[i] = nums[i] + result[i-1]; 
        }
        
        return result; 
    }
};
