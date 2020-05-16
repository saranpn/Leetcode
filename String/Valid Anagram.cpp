//Source: https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/882/
//Author: Saravana Kumar

/* Given two strings s and t , write a function to determine if t is an anagram of s.

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false
Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?

*********************************************************************************************************************/

// Method 1: Using sorting
class Solution {
public:
    bool isAnagram(string s, string t) {
        
        int n1 = s.size();
        int n2 = t.size();
        
        if(n1 != n2)
        {
            return false; 
        }
        
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        
        for(int i=0; i<s.size(); i++)
        {
            if(s[i] != t[i])
            {
                return false;
            }
        }
        
        return true;
    }
};

//Method 2: Using Map (better than sorting) (time complexity would be less) (spce used would be more due to the use of map)

class Solution {
public:
    bool isAnagram(string s, string t) {
        
        int n1 = s.size();
        int n2 = t.size();
        
        if(n1 != n2)
        {
            return false;
        }
        
        unordered_map<char,int> MyMap; //Create a map
        
        for(int i=0; i<n1; i++) //Traverse through both strings
        {
            MyMap[s[i]]++; //Store key and value and increment the occurrence
            MyMap[t[i]]--; //Store key and value and decrement the occurence
        }
        
        //So after this, if it is an anagram, then the value in the map would be "zero" everywhere, due to ++ in one string and -- in other string 
        //If it is not zero then it is not an anagram 
             
        for(auto j : MyMap)
        {
            if(j.second != 0)
            {
                return false;
            }
        }
        return true;
    }
};
