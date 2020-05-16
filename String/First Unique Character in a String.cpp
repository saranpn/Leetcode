//Source: https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/881/
//Aythor: Saravana Kumar 

/* Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
Note: You may assume the string contain only lowercase letters.

*****************************************************************************************************************************/
/*  IDEA: Step 1: Traverse through the string once.
          Step 2: Store the key and its frequency.
          Step 3: Traverse through the string again 
          Step 4: Return the "value" which has only 1 frequency, the index
          Step 5: If there is no unique element return -1
*/

class Solution {
public:
    int firstUniqChar(string s) {
        
        unordered_map<char,int> MyMap;  //Create a map
        
        for(int i : s) //Step 1
        {
            MyMap[i] ++; //Step 2
        }
        
        for(int i=0; i<s.size(); i++) //Step 3
        {
            if(MyMap[s[i]] == 1)   //Check the occurence, which has only 1 
                return i;          // return the index 
        }
        
        return -1; //Step 5
    }
};
