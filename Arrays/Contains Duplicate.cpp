//************************************************  METHOD 1 - Using Sorting *************************************************************
//Time: O(N log N)
//Space: O(1)

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) 
{
    int n = nums.size();

    if(n == NULL || n == 1) return false; //If there is only 1 or 0 number in the array, then return false (No duplicate)

    sort(nums.begin(),nums.end()); //Sorting the array

    //Comapring the adjacent elements
    for(int i=0; i<n-1; i++)
    {
        if(nums[i] == nums[i+1]) return true; //If there's a duplicate 
    }
    return false;  //If there's no duplicate  
}
};

//************************************************  METHOD 2 - Using SET *************************************************************
//Time: O(N log N) 
//Space: O(N)

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) 
    {
        set<int> MySet;  //Set is created 
        
        for(int i =0; i < nums.size(); i++)
        {
            if(MySet.count(nums[i]))
              return true;
            
/* Set is initialized here one by one. If duplicate number is inserted into the set, 
 then for the next itearation it checks for the duplicate element in if loop and returns true */
            MySet.insert(nums[i]);    
        }
        return false; //If there are no duplicates, then it will return false 
    }
};

//************************************************  METHOD 3 - Brute Foce Method *************************************************************
//Time: O(N^2)
//Space: O(1) 

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) 
    {
        int n = nums.size();
        
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                if(nums[i] == nums[j])
                    return true; 
            }
        }
        
        return false; 
    }
};
