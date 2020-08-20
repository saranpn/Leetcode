/* QUESTION: 

You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once. 
Find this single element that appears only once.

Follow up: Your solution should run in O(log n) time and O(1) space.

 

Example 1:

Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2
Example 2:

Input: nums = [3,3,7,7,10,11,11]
Output: 10

*********************************************************************************************************************************************/

// SOLUTION 1: USING MAP (NOT OPTIMAL) 

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) 
    {
        unordered_map<int,int> MyMap;
        
        for(int i=0; i<nums.size(); i++)
        {
            MyMap[nums[i]]++;
        }
        
        for(auto v: MyMap)
        {
            if(v.second == 1)
            {
                return v.first;
            }
        }
        
        return 0;
    }
};
