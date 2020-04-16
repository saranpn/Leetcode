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
        int last_unique = -1;  //first pointer acts as an index to store the unique elements into the nums array
    
        for(int i = 0; i < nums.size(); ++ i) //second pointer also acts as pointer which traverse through the array
        {   //first element in the array is always a unique element. So, last_unique = -1 is only for first iteration and keep the first element in the same place itself. 
            
            //Then from second iteration, check for the unique number, if we find it then throw that element into the vector
            
            if(last_unique == -1 || nums[i] != nums[last_unique]) 
                nums[++last_unique] = nums[i];
        }
        
        return last_unique+1; //So, the last_unique value is incremented only when the loop finds the unique number, and +1 is to find the total length
    }
};
