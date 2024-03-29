//Source: https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/883/
//Author: Saravana Kumar

/* Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.

Example 1:

Input: "A man, a plan, a canal: Panama"
Output: true
Example 2:

Input: "race a car"
Output: false

*********************************************************************************************************************/

// IDEA: USING TWO POINTER TECHNIQUE
// Time: O(N)
// Space: O(1)

class Solution {
public:
    bool isPalindrome(string s) {
        
        int n = s.size()-1; //size of the string 
        int left = 0; //left pointer starts from zero index
        int right = n; //right index starts from last index
        
        while(left < right) //Continue untill left index passes the right index
        {
            //SYNTAX: isalnum("value")
            if(!isalnum(s[left])) //if s[left] is not an alphanumeric value, then enter the if case 
            {
                left ++; //increment the left value --> meaning just ignore it by incrementing
                continue; //then continue the while loop with new left index
            }
            if(!isalnum(s[right])) //same for right
            {
                right --; //decrement the right value 
                continue;
            }
            
// Here we are are considering everything as lowercase i.e. change the upper case to lower using tolower function. 
       
            if(tolower(s[left]) != tolower(s[right])) return false; //if not equal 
            
            else
            {
                left ++;
                right --;
            }
            
        }
        
        return true; //Return true if it is a palindrome
    }
};


//******************************************* Solution 2: Using Stack ***********************************************************************
// Time: O(N)
// Space: O(N)

class Solution {
public:
    bool isPalindrome(string s) 
    {
        int n = s.size();
        
        stack<char> MyStack;
        
        //Traverse array and push it into Stack
        for(int i=0; i<n; i++)
        {
            if(isalnum(s[i])) //Push only upper and lower case letters 
            {
                MyStack.push(s[i]);
            }
        }
        
        //Traverse array and compare it to the Top element in the Stack 
        for(int i=0; i<n; i++)
        {
            if(isalnum(s[i]))
            {
                if(tolower(MyStack.top()) != tolower(s[i]))
                {
                    return false;
                }

                MyStack.pop();
            }
        }

        return true;
    }
};
