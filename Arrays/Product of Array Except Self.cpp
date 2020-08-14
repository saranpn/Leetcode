/* Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Example:

Input:  [1,2,3,4]
Output: [24,12,8,6]
Constraint: It's guaranteed that the product of the elements of any prefix or suffix of the array (including the whole array) fits in a 32 bit integer.

Note: Please solve it without division and in O(n).

Follow up:
Could you solve it with constant space complexity? */

/********************************************************************************************************************************************************/


// Time: O(N) (Traversing the arrray twice) 
// Space: O(N) (Creating an extra array for storing the result

// This solution won't work if there is a zero in the array. 


/* Idea: Multiply all the elements in the array and calculate total product value. Then traverse the array and divide each value by the current i value, 
         to get the multiplication of all the other elements  */
         
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        vector<int> result;
        int totalproduct = 1;
        
        for(int i=0; i<nums.size(); i++)
        {
            totalproduct = totalproduct * nums[i];
        }
        
        for(int j=0; j<nums.size(); j++)
        {
            result.push_back(totalproduct/nums[j]);
        }
        
        return result; 
    }
};



// ONLINE COMPILER SOLUTION: 

#include <iostream>
#include<vector> 
#include<unordered_map>

using namespace std;

int main()
{
    vector<int> nums = {1,2,3,4};

    vector<int>result;
    
    int totalproduct = 1; 

    for(int i=0; i<nums.size(); i++)
    {
        totalproduct = totalproduct * nums[i];
        
    }
    
    cout << "totalproduct = " << totalproduct << endl;
    
    for(int i=0; i<nums.size(); i++)
    {
        result.push_back(totalproduct/nums[i]);
    }
    
    for(int j=0; j<result.size(); j++)
    {
        cout << result[j] << " ";
    }

    return 0;
}

