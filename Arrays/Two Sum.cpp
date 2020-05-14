/* Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1]

********************************************************************************************************************/
// IDEA 1: Use Map for better time complexity. So that we can go throught the array only once. 
//TIME COMPLEXITY: O(N)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int> result;   // To return the "result" vector
        
        int n = nums.size();  
        
        int diff; // To find the difference between target and the picked element
        
        unordered_map<int,int> m;  // Create a map
        
        for(int i=0; i<nums.size(); i++)
        {
            diff = target - nums[i];  // Pick every element in an array and calculate the difference = target - pickedElement
            
  //Check the difference we found is in there in the map (AND) the index of the difference is not equal to the index of the picked element
  
            if(m.find(diff) != m.end() && m.find(diff)->second != i)
            {
                result.push_back(m.find(diff)->second);  //push the index of the difference 
                result.push_back(i); //push the index of the picked element
                
                return result; //return the result
            }
            m[nums[i]] = i; // if the conditions are not satisfied, we need to store the element with its index in the map
        }
        return result; //if we don't find the solution, return the empty vector
    }
};

//IDEA 2: BRUTE FORCE method.
// TIME COMPLEXITY: O(n^2) since we are going through the array twice

/* Step 1: Pick every element in an array and add it with every other element ahead of the picked element. 
   Step 2: After every add, check if the sum is equal to target
   Step 3: If Yes, we have our solution, push it to the result vector and return it.
   Step 4: If No, pick next element, and add with all the elements AHEAD of it. */
   
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int> result;
        
        for(int i=0; i<nums.size()-1; i++)
        {
            for(int j=i+1; j<nums.size(); j++)
            {
                if(nums[i] + nums[j] == target)
                {
                    result.push_back(i);
                    result.push_back(j);
                    return result;
                }
            }
        }
        
        return result;
    }
};
