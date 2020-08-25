/* QUESTION: 

Given a sorted (in ascending order) integer array nums of n elements and a target value, write a function to search target in nums. 
If target exists, then return its index, otherwise return -1.


Example 1:

Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4

***************************************************************************************************************************************************/

/* IDEA: Take 3 pointers. 2 pointer "left" and "right" outside the while loop and 1 pointer "middle" inside the while loop. 
         If the nums[middle] == target, return it. 
         or else continue to divide the array into half depending upon the target value and the element. 

             //TIME COMPLEXITY: O(log N) --> WHY ?? Because we are eliminating half of our array at every time we traverse. That gives us the time complexity O(log N) 
             //SPACE COMPLEXITY: O(1) --> Constant Time                                   
                                              

//************************************************ Only applicable for "SORTED" array *************************************************************/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        if(nums.size() == 0)
        {
            return -1; 
        }
        
        int left = 0;
        int right = nums.size()-1; 
        
        while(left<=right)
        {
            int middle = left + (right-left)/2;
            
            if(target == nums[middle])
            {
                return middle;
            }
            else if(target > nums[middle])
            {
                left = middle + 1;
            }
            else if(target < nums[middle])
            {
                right = middle - 1;
            }
        }
        
        return -1; 
    }
};

/* QUESTION: Why middle Element is found this way ?? 

--> An easy way to find the middle would be: middle=(start+end)/2middle=(start+end)/2. 
--> For C++, this equation will work for most cases, but when start or end is large, this equation will give us the wrong result due to integer overflow. 
--> Imagine that start is equal to the maximum range of an integer. Now adding anything to start will result in an integer overflow. 
--> Since we need to add both the numbers first to evaluate our equation, an overflow might occur. 
--> The safest way to find the middle of two numbers without getting an overflow is as follows: middle  = start + (end-start)/2
*/

