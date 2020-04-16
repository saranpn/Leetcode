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

//************************************************  METHOD 1 - Using STL (Not Optimal) ******************************

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) 
        
    {
    
    //If there is only 1 number in the array
    if(nums.size() <= 1) 
    {
        return 0;
    }
        
    //Sorting the array
    sort(nums.begin(), nums.end());
    
    //Comapring the adjacent elements
    for(int i = 0; i < nums.size() - 1; ++i)
    {
        if(nums[i] == nums[i+1])
        {   

            return 1;    //If true, return 1 and exit the function
        }
    }
            return 0;   //If false, return and exit the function 
}
};
//************************************************  METHOD 2 - Using SETS ******************************

