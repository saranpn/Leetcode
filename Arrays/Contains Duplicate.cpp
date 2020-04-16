//Author: Saravana Kumar  
//Source: https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/578/

/*************************************************************************************************
Given an array of integers, find if the array contains any duplicates.

Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.

Example 1:

Input: [1,2,3,1]
Output: true
Example 2:

Input: [1,2,3,4]
Output: false
***************************************************************************************************/

//************************************************  METHOD 1 - Using STL ******************************

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) 
        
    {
        
    if(nums.size() <= 1) return 0;
    
    sort(nums.begin(), nums.end());
    
    for(int i = 0; i < nums.size() - 1; ++i)
    {
        if(nums[i] == nums[i+1])
        {   
            cout << "True";
            return 1;
        }
        else
        {   
            cout << "False";
            return 0;
        }
    }
    
    return 0; 
}
};

//************************************************  METHOD 2 - Using SETS ******************************

