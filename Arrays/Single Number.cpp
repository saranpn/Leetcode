Source: https://leetcode.com/problems/single-number/
Author: Saravana Kumar 

/*******************************************************************************************
Given a non-empty array of integers, every element appears twice except for one. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:

Input: [2,2,1]
Output: 1
Example 2:

Input: [4,1,2,1,2]
Output: 4

******************************************************************************************/

//Time: O(N)
//Space: O(1) 

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int m = 0; //First pointer
        
        for(int i=0; i<nums.size(); i++) //second pointer 
        {
            m = m ^ nums[i];
        }
        
        return m;
    }
};


/* NOTE: XOR only has two properties

    1. XOR of a number with the same number gives zero. Example: 2 ^ 2 = 0 
    2. XOR of a number with zero gives that number itself. Example: 3 ^ 0 = 3
    3. XOR of a number with the different number gives the sum of two numbers. Example: 2 ^ 4 = 6
    
    [Then what about XOR of a number with another different number] --> It modify/arrange itself
        m = 4 ^ 1 ^ 2 ^ 1 ^  2 
        m = 4 ^ 1 ^ 1 ^ 2 ^ 2 
        m = 4 ^ 0 ^ 0
        m = 4 ^ 0 
        m = 4    
        
        */
