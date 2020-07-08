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
        
    if(nums.size() == 0) return 0;
    if(nums.size() == 1) return 1; 
        
    int next = 1; //2nd pointer i for next non duplicate element 
    for(int i=0; i<nums.size(); i++) //1st pointer i for iteration
    {
        if(nums[next-1] != nums[i])
        {
            nums[next] = nums[i]; //inserting the unique element into the vector 
            next++; //Incrementing Next pointer (OR) Finall finding the number of unique elements
        }
    }
    
    return next; //answer 
    }
};

/* IDEA: Using two pointer  
         1st pointer --> used for iteration
         2nd pointer --> used to find next non duplicate element
         
         Comapare the values of 1st and 2nd pointer 
         
         This 2nd pointer will be incrememted only if it finds the            next non duplicate element. 
         
         Return the 2nd pointer. 
    
*/ 
