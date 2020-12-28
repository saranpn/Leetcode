/********************************************************** SOLUTION 2: Using Hash Set ***************************************************
//Time: O(N)
//Space: O(N)

/* IDEA: Add the elements into the Set
         Then if "i" is not in the Set, then add that to the result
*/

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) 
    {
        set<int> MySet;
        vector<int> result; 
        int n = nums.size();
        
        for(int i=0; i<n; i++)
        {
            MySet.insert(nums[i]);
        }
        
        for(int i=1; i<=n; i++)
        {
            if(!MySet.count(i)) 
                result.push_back(i);
        }
        return result; 
    }
};
