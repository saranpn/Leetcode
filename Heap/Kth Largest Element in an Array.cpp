// Author: Saravana Kumar
// Source: https://leetcode.com/problems/kth-largest-element-in-an-array/

//***************************************************** SOLUTION 1: Using HEAP (Best) *******************************************************
//Time: O(N log k)
//Space: O(k)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        struct greaters
        {  
            bool operator()(const long& a,const long& b) const
            {  return a>b;  }  
        }; 
        
        vector<int> result(nums.begin(), nums.begin()+k);
        make_heap(result.begin(), result.end(), greaters());
        
        for(int i=k; i<nums.size(); i++)
        {
            if(nums[i] > result.front())
            {
                //pop out that top number from min-heap
                pop_heap(result.begin(),result.end(),greaters());
                result.pop_back();

                //Add or push that number from the nums vector to the min-heap
                result.push_back(nums[i]);
                push_heap(result.begin(), result.end(), greaters());
            }
        }
        
        return result.front();
    }
};

//***************************************************** Solution 2: Using Heap (With Priority Queue) **********************************************
//Time: O(N log k)
//Space: O(k)

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        int n = nums.size();
        
        priority_queue<int> Q;
        
        for(int i=0; i<n; i++)
        {
            Q.push(nums[i]);
        }
        
        for(int j=0; j<k-1; j++)
        {
            Q.pop();
        }
        
        return Q.top();
    }
};

//***************************************************** SOLUTION 3: Using Sorting Technique *******************************************************
//Time: O(N log N)
//Space: O(k) 

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        int ans = 0;
        sort(nums.begin(),nums.end(), greater<int>());
        return nums[k-1];
    }
};
