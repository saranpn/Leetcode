//*************************************************** SOLUTION 1: Using MAP **************************************************************
//Time: O(N)
//Space: O(N)

class Solution {
public:
    int findDuplicate(vector<int>& nums) 
    {
        int n = nums.size();
        
        unordered_map<int,int> MyMap;
        
        for(int i=0; i<n; i++)
        {
            MyMap[nums[i]]++;
        }
        
        for(auto v : MyMap)
        {
            if(v.second >= 2)
            {
                return v.first;
            }
        }
        
        return 0;
    }
};

//*************************************************** SOLUTION 2: Using Set **************************************************************
//Time: O(N)
//Space: O(N)

class Solution {
public:
    int findDuplicate(vector<int>& nums) 
    {
        int n = nums.size();
        int ans = 0; 
        
        set<int> MySet;
        
        for(int i=0; i<n; i++)
        {
            if(MySet.count(nums[i]))
            {
                ans = nums[i];
            }
            
            MySet.insert(nums[i]);
        }
        
        return ans; 
    }
};

//*************************************************** SOLUTION 3: Using Sorting Technique ************************************************
//Time: O(N log N)
//Space: O(1)

class Solution {
public:
    int findDuplicate(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        
        int n = nums.size();
        int ans = 0;
        
        int left = 0;
        int right = 1;
        
        while(right<n)
        {
            if(nums[left] != nums[right])
            {
                left++;
                right++;
            }
            else if(nums[left] == nums[right])
            {
                ans = nums[left];
                break;
            }
        }
        
        return ans; 
    }
};
