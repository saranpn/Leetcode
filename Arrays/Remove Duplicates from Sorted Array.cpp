//Source: https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/727/
//Author: Saravana Kumar

/*******************************************************************************************************

Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

Example 1:

Given nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.

It doesn't matter what you leave beyond the returned length.

******************************************************************************************************/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int index = 0;    //first pointer "index"
        
        for(int i=0; i<nums.size(); i++) //second pointer "i" 
        {
            if(nums[i] != nums[index])  //comparing the adjacent elements, if they are not equal then increase the index and store i value in that index
               nums[++index] = nums[i] ;
        }
        return index+1; //So, the index value is incremented only when the loop finds the unique number, and +1 is to find the total length
    }
};
