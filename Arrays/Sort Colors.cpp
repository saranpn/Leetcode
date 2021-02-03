//************************************************************** TWO PASS SOLUTION **********************************************************

class Solution {
public:
    void sortColors(vector<int>& nums) 
    {
        int n = nums.size();
        int ZeroCount = 0;
        int OneCount = 0;
        int TwoCount = 0;
        
        for(int i=0; i<n; i++)
        {
            if(nums[i]==0) ZeroCount++;
            else if(nums[i]==1) OneCount++;
            else if(nums[i]==2) TwoCount++;
        }
        
        for(int i=0; i<n; i++)
        {
            if(ZeroCount > 0)
            {
                nums[i] = 0;
                ZeroCount--;
            }
            
            else if (OneCount > 0)
            {
                nums[i] = 1;
                OneCount--;
            }
            
            else if(TwoCount > 0)
            {
                nums[i] = 2;
                TwoCount--;
            }
        }
    }

};
