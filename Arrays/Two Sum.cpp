/* Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1]

***************************************************************************************************************************************************/
//SOLUTION 1: Using Sorting Technique --> MOST OPTIMAL 
//TIME COMPLEXITY: O(N log N) 
//SPACE COMPLEXITY: O(1) 

// NOTE: This method cannot be used if want to return the indices, since after sorting, the index positions of all the element changes 

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        sort(nums.begin(),nums.end()); 
        
        //{2,3,4}
        
        vector<int> result; //to store the result 
        
        int left = 0;
        int right = nums.size() - 1;
    
        while(left < right)
        {
            int sum  = nums[left] + nums[right];

            if(sum == target)
            {
                result.push_back(left);
                result.push_back(right);
                return result; 
            }
            else if(sum > target) //if sum is greater than target
            {
                right --; //decrement right pointer 
            }
            else if(sum < target) //if sum is lesser than target
            {
                left ++; //increment left pointer 
            }
        }

        return result; 
}
        
};

//*************************************************************************************************************************************************

// SOLUTION 2: Use Map for better time complexity. So that we can go throught the array only once. 
//TIME COMPLEXITY: O(N)
//SPACE COMPLEXITY: O(N) --> because of map 

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

//***********************************************************************************************************************************************
//SOLUTION 3: BRUTE FORCE method.
// TIME COMPLEXITY: O(n^2) --> since we are going through the array twice
// SPACE COMPLEXITY: O(1) --> since we are going to stay only 2 numbers in the result vector 

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
