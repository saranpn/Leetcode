//Source: https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/880/
//Author: Saravana Kumar 

/* Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output: 321
Example 2:

Input: -123
Output: -321
Example 3:

Input: 120
Output: 21
Note:
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. 
For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.

****************************************************************************************************************/

/* IDEA: (This idea will work only for smaller numbers, but not for zero and larger numbers)

          Step 1: Initialize a variable ans with zero
          Step 2: Inside a while loop(n!=0)
          Step 3: ans = (ans *10) + (x%10)
          step 4: x = x/10
          
  ****************************************************************************************************************/
  
class Solution {
public:
int reverse(int x) {
    
      int a = INT_MAX; //will store the largest +ve number c++ can take 
      int b = INT_MIN; //will store the largest -ve number c++ can take

      int ans = 0; //Step 1
    
      while(x != 0) //Step 2
      {
        //if the x value is much larger, at some point the "ans" in step 3 would be larger than the INT_MAX, if that's the case simply exit the while loop. //Same for smallest x value. 
        if(a/10 < ans) return 0; 
        if(b/10 > ans) return 0;
          
        ans = ans * 10 + x % 10; //Step 3 
        x = x / 10; //Step 4
      }
      
      return ans;
    }
};
  
 

