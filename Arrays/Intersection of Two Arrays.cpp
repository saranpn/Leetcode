Source: https://leetcode.com/problems/intersection-of-two-arrays/
Author: Saravana Kumar

/*******************************************************************************
Given two arrays, write a function to compute their intersection.

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Note:

Each element in the result must be unique.
The result can be in any order
*********************************************************************************/

/* IDEA: Step 1: Store the elements of num1 vector and store in the unordered set.
         Step 2: Take the element from num2 vector and see if it is there in the set
         Step 3: If it is present, push that element to the result vector  */

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        //Step 1: Store the elements of num1 vector and store in the unordered set
        // Why Unordered set ?? Here we don't care about the order of the elements. So, we use unoredered set to store 
        // unique elements from num1 to store it in the unordered set.
        
        unordered_set<int> MySet(nums1.begin(),nums1.end());
        
        //Create a vector called "result" to store the result
        vector<int> result;
        
        //Use For each loop to go through all the elements in the vector num2 and compare it with unordered set
        for(int a: nums2)             //This line will go through all the elements in the num2 vector
        {
            if(MySet.count(a))        //Step 2: Take an element from num2 vector and see if it is there in the MySet
            {
                result.push_back(a);  //Step 3: If it is present, push it into the result vector. 
                MySet.erase(a);       // Then erase that element from the set, so that when next time an element is checked with set, it won't be present. 
            }
        }
        
        return result;               //Return the result vector 
    }
};
