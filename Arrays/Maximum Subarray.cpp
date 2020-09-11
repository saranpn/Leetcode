class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int currMax = nums[0];
        int maxSoFar = nums[0];

        for (int i = 1; i < nums.size(); i++) 
        {
        /* Standing at a number we need to ask, 
            1) By adding this number to the previous contiguous number will give us the maximum sum (OR)
            2) By adding this number individually (which also means starting new contiguous sub-array) will give us the maximum sum   */ 
            
          int extend = currMax + nums[i]; //extend the contiguous subarray with previous numbers 
          int start_new = nums[i]; //do we need to start the new contiguous sub_array by adding that number individually
          currMax = max(extend, start_new); //then select the maximum number out of this two 
            
          /* Now we need to make sure that, this maximum number we obtained now is the maximum so far ?? 
          
              Then check, if that current maximum is the maximum number we obtained so far. 
              If yes, then keep the current max number as maxSoFar 
              If No, then keep the previous maxSoFar as new maxSoFar   */
        
          maxSoFar = max(maxSoFar, currMax);  
        }

        return maxSoFar; //Finally return the maxSoFar 
    }
};
