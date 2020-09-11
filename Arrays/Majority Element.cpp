
//*********************************************************** SOLUTION 1: Using Hash Map ********************************************************************************
//Time Complexity: O(N) 
//Space Complexity: O(N) 

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


//****************************************************************  Solution 2: Using Sorting  *************************************************************************** 

//Time Complexity: O(N log N) --> Because for sorting, time complexity is always O(N log N), where N is the number of elements we are sorting 
//Space Complexity: O(1) --> We are not using any extra space here 

class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        //vector<int> nums = {1,1,2,2,5,5,5,5,2};
        
        sort(nums.begin(),nums.end());
        
        return nums[nums.size()/2]; //after sorting the majority element would be the center element in the array.
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
