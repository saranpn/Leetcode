//****************************************************** Solution 1: Sliding Window Approach **************************************************
//Time: O(N)
//Space: O(1)

class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int currMax = nums[0];
        int maxSoFar = nums[0];

        int n = nums.size();
        
        for (int i = 1; i < n; i++) 
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

//**************************************************************** SOLUTION 2: QUADRATIC TIME ***************************************************************
//TIME: O(N^2)
//SPACE: O(1) 

/* Here, we make use information we already have for the previous subarray sum */

class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int n = nums.size();
        int maxSoFar = INT_MIN;

        for (int left = 0; left < n; left++)
        {
            int currMax=0;
            for(int right=left; right<n; right++) 
            {
                currMax = currMax + nums[right]; //Calculate the currMax
                maxSoFar = max(maxSoFar, currMax); //Choose the maxSofar 
            }
        }

        return maxSoFar; //Finally return the maxSoFar 
    }
};

//**************************************************************** SOLUTION 3: CUBIC TIME ***************************************************************
//TIME: O(N^3)
//SPACE: O(1) 

/* Cubic Solution will calculate the subarray sum by going all the way back to the beginning for every subarray.
   So here we would be repeating the work. Calculating the sum of every subarray from the beginning. */

class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int n = nums.size();
        int maxSoFar = INT_MIN;

        for (int left = 0; left < n; left++)
        {
            for(int right=left; right<n; right++) 
            {
                int currMax=0;
                for(int k=left; k<=right; k++) //Go all the back to the beginning to calculate the subarray 
                {
                    currMax = currMax + nums[k]; //Calculate the currMax 
                }
                
                maxSoFar = max(maxSoFar, currMax); //Choose the maxSofar 
            }
        }

        return maxSoFar; //Finally return the maxSoFar 
    }
};
