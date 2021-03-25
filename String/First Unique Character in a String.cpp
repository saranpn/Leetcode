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
/*  Solution1: Using Maps

          Step 1: Traverse through the string once.
          Step 2: Store the key and its frequency.
          Step 3: Traverse through the string again 
          Step 4: Return the "value" which has only 1 frequency, the index
          Step 5: If there is no unique element return -1
*/

// Time Complexity : (2*N) => O(N) (Since we are traversing twice) 

class Solution {
public:
    int firstUniqChar(string s) {
        
        unordered_map<char,int> MyMap;  //Create a map
        
        for(int i = 0; i<s.size(); i++) //Step 1
        {
            MyMap[s[i]] ++; //Step 2
        }
        
        for(int i=0; i<s.size(); i++) //Step 3
        {
            if(MyMap[s[i]] == 1)   //Check the occurence, which has only 1 
                return i;          // Step 4 -> return the index 
        }
        
        return -1; //Step 5
    }
};

/***********************************************************************************************************************/

// Solution 2: Using Vector by using ASCII method

class Solution {
public:
    int firstUniqChar(string s) {
        
        vector<int> result(26,0);
        
        for(int i=0; i<s.size(); i++) //Traverse through thr string for each char
        {
            //Subtract each character with a (i.e. 97) --> we will get a number for each character
            // e will be 5, c will be 3... etc. 
            //This number will act as an index for the result vector we created
            //temp is used to store index value for all the letters. 
            int temp = s[i] - 'a';    
            
            //Increment that index value by 1 
            //Increment 1 everytime whenever that index value appears
            // (in our case 'e' index value which is 5 will appear thrice, so it is incremented 3 times)
            result[temp]++;
        }
        
        //Traverse though the result vector and find the first element whose value is 1 and return it.
        //We only need to traverse for the number of characters time in the result vector and it should be in the same  order of the char given to return the first unique character
        for(int j=0; j<s.size(); j++) 
        {
            int temp = s[j] - 'a'; //Get the index value of the character giver
            if(result[temp] == 1)      // And check if it's frequency is only 1 times
            {
                return j;          //if Yes, return that index 
            }
        }
        
        return -1; //If no unique element is found 
        
    }
};

//********************************************** Solution 3: Brute Force **************************************************************
// Time: O(N^2)
// Space: O(1) 

class Solution {
public:
    int firstUniqChar(string s) 
    {
        int n = s.size();
        
        int ans = -1;
        
        int count = 0;
        
        string copy;
        
        for(int i=0; i<n; i++)
        {
            copy[i] = s[i];
        }
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(s[i] != copy[j]) count++;
                
                if(count == n-1) return i; 
            }
            
            count = 0;
        }
        
        return ans; 
    }
};





