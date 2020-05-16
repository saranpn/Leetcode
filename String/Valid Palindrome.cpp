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
            
//Two things to be noted in this if case:
// 1. Here we are are considering everything as lowercase i.e. change the upper case to lower using tolower function. 
// 2. With only the "condition" of if loop we can increment or decrement the values without even entering the if case. 
            
//if the values are equal just increment left and right pointers without entering the if case
//if the values are equal then enter the if case and return flase
            
            if(tolower(s[left++]) != tolower(s[right--])) 
            {
                return false;
            }
            
        }
        
        return true; //Return true if it is a palindrome
    }
};
