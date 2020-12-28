//*********************************************************** SOLUTION 1: Using Bit Manipulation *******************************
//Time: O(N)
//Space: O(1) 

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int m = 0; //First pointer
        
        for(int i=0; i<nums.size(); i++) //second pointer 
        {
            m = m ^ nums[i];
        }
        
        return m;
    }
};


//*********************************************************** SOLUTION 2: Using Hash Map ******************************************
//Time: O(N)
//Space: O(N)

class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        unordered_map<int,int> MyMap;
        int ans = 0;
        int n = nums.size();
        
        for(int i=0; i<n; i++)
        {
            MyMap[nums[i]]++;
        }
        
        for(auto v: MyMap)
        {
            if(v.second == 1)
                ans = v.first;
        }   
        return ans; 
    }
};

//*********************************************************** SOLUTION 3: Using Hash Set ******************************************
//Time: O(N)
//Space: O(N)

/* IDEA: Add unique element to the list.
         If the element is not unique then remeove that element from the list
         Finally you will be left with only 1 single unique number 
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
    set<int> MySet; 
    int n = nums.size();
    
    for(int i=0; i<n; i++)
    {   
        if(MySet.count(nums[i])) //If the value is found, then it is a duplicate element, 
            MySet.erase(nums[i]); //So remove that from the set 
        else
            MySet.insert(nums[i]); //If the value is not found, then insert it into the set. 
    }
    
    //Traverse the Set and return the Single Number 
    for(int v: MySet)
    {
        return v;
    }     
    return -1; 
    }
};
