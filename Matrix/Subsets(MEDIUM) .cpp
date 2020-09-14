/* IDEA: 
               result  { {} }
1st iteration: result  { {}, {1}} //keep the result and add 1st element to result
2nd iteration: result  { {}, {1}, {2}, {1,2}} //keep the result and add the 2nd element to the result 
3rd iteration: result  { {}, {1}, {2}, {1,2}, {3}, {1,3}, {2,3}, {1,2,3}} //Keep the result and add 3rd element to the result

Size of the Matrix = 2^(Number of elements)

*/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        //if the nums vector is empty, then simply return null empty set
        if(nums.size() == NULL) return { {} };
        
        //create a vector called result to store the result, and initialize with empty set 
        vector<vector<int>> result = { {} };
        
        //Traverse the nums vector
        for(int i=0; i<nums.size(); i++)
        {
            int n = result.size(); //result matrix size will change for every "i" iteration 
            for(int j=0; j<n; j++) //traverse through the result vector
            {   vector<int> vec = result[j]; //For every single element in the result, 
                vec.push_back(nums[i]); //Take that element and append it to all the  elements in nums vector
                result.push_back(vec); //Finally append that vector into the result matrix 
            }
        }
        
        return result; //Finally return the result 
    }
};
