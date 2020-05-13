/* Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Example:

Input: [0,1,0,3,12]
Output: [1,3,12,0,0]
Note:

You must do this in-place without making a copy of the array.
Minimize the total number of operations.

*****************************************************************************************************/
/* IDEA: By using Inplace method without using extra space (vector). So, we here use two pointers called left and right.
         At first both left and right pointer will be pointing on the zero index. 
         Right pointer used to see if it is zeor or non zero element.
         If it is zero, don't do anything just increment the right pointer.
         If it is non-zero element, swap it with left pointer which is pointing the index and then increment both left and right pointer.

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int n = nums.size(); //Size of the vector
        
        if(n == 0 || n == 1)  //If the vector has no elements are just only one element just return
            return;
        
        int left = 0;   //left pointer initialized to zero  
        int right = 0;  //right pointer initialized to zero
        
        while(right < n)    //while right pointer is less than the size of the vector, which will be pointing on the last element
        {
            if(nums[right] == 0)  //if the value is zero, 
                right++;          //just increment the right
            else                  //if the value is non zero
            {
                swap(nums[left], nums[right]); //swap the value in the left and right pointer 
                left++; //increment left pointer
                right++; //increment right pointer
            }
        }
    }
};
