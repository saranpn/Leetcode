//TIME: O(N) --> Traversing array once 
//SPACE: O(1) --> No Extra Array

class Solution {
public:
    void moveZeroes(vector<int>& nums) 
    {
        int n = nums.size();
        int i = 0; //Start from 0th index 
        int j = 1; //Start from 1st index 
        
        while(j < n)
        {
            //Case 1: Increment i
            if(nums[i]!=0 && nums[j] ==0) i++;
            
            //Case 2: Increment j
            else if(nums[i]==0 && nums[j]==0) j++;
                    
            //Case 3: Increment both i and j
            else if(nums[i]!=0 && nums[j] !=0) 
            {
                i++;
                j++;
            }
            
            //Case 4: Swap only if i=0 and j !=0, and then increment i and j 
            else if(nums[i]==0 && nums[j]!=0)
            {
                swap(nums[i],nums[j]);
                i++;
                j++;
            }
        }
    }
};


/****************************************************** SOLUTION 1: In place solution ****************************************************************************
//TIME: O(N) --> Traversing array once 
//SPACE: O(1) --> No Extra Array

 IDEA: By using Inplace method without using extra space (vector). So, we here use two pointers called left and right.
         At first both left and right pointer will be pointing on the zero index. 
         Right pointer used to see if it is zeor or non zero element.
         If it is zero, don't do anything just increment the right pointer.
         If it is non-zero element, swap it with left pointer which is pointing the index and then increment both left and right pointer */

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int n = nums.size(); //Size of the vector
        
        if(n == 0 || n == 1)  //If the vector has no elements are just only one element just return
            return;
        
        int left = 0;   //left pointer initialized to zero  
        int right = 0;  //right pointer initialized to zero
        
        while(right < n)    //while right pointer is less than the size of the vector, which will be pointing on the last element
        {
            if(nums[right] == 0)  //if the value is zero, 
                right++;          //just increment the right
            else                  //if the value is non zero
            {
                swap(nums[left], nums[right]); //swap the value in the left and right pointer 
                left++; //increment left pointer
                right++; //increment right pointer
            }
        }
    }
};

//FULL CODE: 
#include <iostream>
#include <vector> 
#include <unordered_map> 

using namespace std;

vector<int> MoveZeros(vector<int> nums)
{
  int n = nums.size(); //size of the array 
  int left=0;
  int right=0;

  for(int i=0; i<n; i++) //traverse the array
  {
    if(nums[right] == 0) {
      right++;
    }
    
    else if(nums[right] != 0) {
      swap(nums[left],nums[right]);
      left++;
      right++;
    }
  }
 
  //For printing out the result 
 for(int i=0; i<n; i++)
 {
   cout << nums[i] << " ";
 }
  
 return nums; 
}

int main() {
    
  vector<int> nums = {0,1,0,3,12}; 

  MoveZeros(nums);
  
  return 0;
}

/****************************************************** SOLUTION 2:Using Extra Array ****************************************************************************/

//TIME: O(N) --> Traversing array once 
//SPACE: O(N) --> Using Extra Array

/* IDEA: Traverse through the array once, and push the elements to the newly created array (only if is a non-zero element) 
         Then, find the number zeros, that we need to push by, #of Zeros = (size of nums) - (size of result) 
         And then push the zeros into the result vector */ 

class Solution {
public:
    void moveZeroes(vector<int>& nums) 
    {
        vector <int> result; 
        int n = nums.size();
        
        for(int i=0; i<n; i++)
        {
            if(nums[i] != 0)
            {
                result.push_back(nums[i]);
            }
        }
        
        int m = result.size();
        
        int count = n - m;
        
        for(int i=0; i<count; i++)
        {
            result.push_back(0);
        }
    }
};

//FULL CODE: 
#include <iostream>
#include <vector> 
#include <unordered_map> 

using namespace std;

vector<int> MoveZeros(vector<int> nums, vector<int> result)
{
    int n = nums.size(); //size of the array 

    for(int i=0; i<n; i++) //traverse the array
  {
      if(nums[i] != 0) 
      {
        //and push only the non-zero elements into the result vector 
          result.push_back(nums[i]);
      }
  }
  
  int m = result.size(); //Get the size of the result array 
  int count = n - m; //This will give us the number of 0's that we need to push back it to the result vector 

  for(int i=0; i<count; i++) { //push the zeros 
      result.push_back(0);
  }
  
  int new_m = result.size(); //Get the new size of the result vector 
 
  //For printing out the result 
  for(int i=0; i<new_m; i++) {
    cout << result[i] << " ";
  }
  
  return result; //Finally return the result
  
}

int main() {
    
  vector<int> nums = {0,1,0,3,12}; 
  
  vector <int> result; 
  
  MoveZeros(nums,result);
  
  return 0;
}
