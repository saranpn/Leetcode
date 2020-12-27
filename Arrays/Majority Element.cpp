//*********************************************************** SOLUTION 1: Using Counter ********************************************************************************
//Time Complexity: O(N) 
//Space Complexity: O(1) 

/* IDEA: Since the majority element is more than N/2 times, even if we cancel all the other element with the majority element, 
                we would still be left with 1 element which would be the majority element */

class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        int n = nums.size();
        
        int majority = NULL;
        int count = 0; 
        
        for(int i=0; i<n; i++)
        {
            //whenenver count is 0, assign new majority element
                //For first iteration, first element would be the majority element
                //For other iteration, count will be zero, means all the other elements got cancelled out, so we need to assign new majority element 
            if (count == 0) majority = nums[i]; 
            
            if(nums[i] == majority) //if element equals to majority element,
                count = count + 1;  //then increment count 
            else if(nums[i] != majority) //if element is not equals to majority element
                count = count - 1;  //then decrement count 
        }
        
        return majority; //Finally return the majority element 
    }
};


//*********************************************************** SOLUTION 2: Using Hash Map ********************************************************************************
//Time Complexity: O(N) 
//Space Complexity: O(N) 

class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        unordered_map<int,int> MyMap; 
        
        int ans = 0; 
        int n = nums.size();
        
        for(int i=0; i<n; i++)
        {
            MyMap[nums[i]]++;
            
            if(MyMap[nums[i]] > n/2) ans = nums[i];
        }
        return ans; 
    }
};

//FULL CODE: 
#include <iostream>
#include <vector> 
#include <unordered_map> 

using namespace std;

int MajorityElement(vector<int> nums, int result) 
{
   unordered_map<int,int> MyMap;
  
  int n = nums.size();
  
   for(int i=0; i<n; i++)
   {
      MyMap[nums[i]] ++;
     
      if(MyMap[nums[i]] > n/2)
      {
        result = nums[i];
        cout << "result = " << result << endl; 
      }
   }
  
  return result; 
}


int main() {
    
  vector<int> nums1 = {3,2,3};
  vector<int> nums2 = {2,2,1,1,1,2,2};
  int result = 0; 
  
  MajorityElement(nums1, result);
  MajorityElement(nums2, result);
  
  return 0;
}


//****************************************************************  Solution 3: Using Sorting  *************************************************************************** 

//Time Complexity: O(N log N) --> Because for sorting, time complexity is always O(N log N), where N is the number of elements we are sorting 
//Space Complexity: O(1) --> We are not using any extra space here 

class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        int n = nums.size();   
        
        sort(nums.begin(), nums.end());
        
        return nums[n/2];
    }
};



//FULL CODE: 
#include <iostream>
#include <vector> 
#include <algorithm>

using namespace std;

int MajorityElement(vector<int>& nums, int result) 
{
  sort(nums.begin(), nums.end());
       
  result = nums[nums.size()/2];
  
  cout << "result = " << result << endl; 
  
  return result; 
}


int main() {
    
  vector<int> nums1 = {3,2,3};
  vector<int> nums2 = {2,2,1,1,1,2,2};
  int result = 0; 
  
  MajorityElement(nums1, result);
  MajorityElement(nums2, result);
  
  return 0;
}
