// Source: https://www.youtube.com/watch?v=qgizvmgeyUM&ab_channel=takeUforward

//Time: O(3N)
//Space: O(N) 

class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        int n = nums.size();
        
        set<int> MySet; 
        
        for(int i=0; i<n; i++)
        {
            MySet.insert(nums[i]);
        }
        
        int longestStreak = 0;
        
        for(int i=0; i<n; i++)
        {
            int k = nums[i] - 1;
            if(!MySet.count(k))
            {
                int currentNum = nums[i];
                int currentStreak = 1;
                
                while(MySet.count(currentNum+1))
                {
                    currentNum++;
                    currentStreak++;
                }
                
                longestStreak = max(longestStreak,currentStreak);
            }
                
        }
        
        return longestStreak; 
    }
};
