
//SOLUTION 1: Using Hash Map

class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        unordered_map<int,int> MyMap;
        
        for(int i=0; i<nums.size(); i++)
        {
            MyMap[nums[i]] ++;
            
            if(MyMap[nums[i]] > nums.size()/2 )
                return nums[i];
        }
        
        return -1; 
    }
};


//Solution 2: Using Sorting 

class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        //vector<int> nums = {1,1,2,2,5,5,5,5,2};
        
        sort(nums.begin(),nums.end());
        
        return nums[nums.size()/2]; //after sorting the majority element would be the center element in the array.
    }
};
