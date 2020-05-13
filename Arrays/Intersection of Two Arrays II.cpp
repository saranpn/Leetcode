//Source: https://leetcode.com/problems/intersection-of-two-arrays-ii/
//Author: Saravana Kumar

/* Given two arrays, write a function to compute their intersection.

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]
Note:

Each element in the result should appear as many times as it shows in both arrays.
The result can be in any order.

*****************************************************************************************************************/

/*
    IDEA: Use this hash map method when, when you have two arrays and if you want to return the 
    each intersection pair on both the arrays. 
*/

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) 
    {
    map<int,int> MyMap; //Map is created
    
    vector<int> result; //To store the result
    
    for(int i : nums1) //traversing through all the elements in the nums1 vector
    {    
        MyMap[i]++; //Storing each element as key with incremental value according to the frequency of occurence 
    }
    for(int i : nums2) //traversing throught all the elements in teh nums2 vector 
    {
        if(MyMap[i]-- > 0)  // if the element is present in the map as key and if its value(occurence) is greater than 1, 
            result.push_back(i); //then push back that key element to the result vector and decrement its value by 1
    }
        
        return result;  //return the result
        
        //See diagram for better understanding
    }
};
