//Source: https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/528/week-1/3288/
//Author: Saravana Kumar 

/* Given an array of strings, group anagrams together.

Example:

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note:

All inputs will be in lowercase.
The order of your output does not matter.

************************************************************************************************************/
/* METHOD 1: Step 1: Create a unordered map.
             Step 2: Traverse through the string vector, and sort each string
             Step 3: Add the sorted string as key in the Map and add the original string as value in the map as vector. 
             Step 4: Finally, push the values in the map to result vector and return it.
             
             Time Complexity: N(k logk) Because of using sort method to find the Anagram between two strings. 
             Explanation: k -> Maximum length of 1 string, N -> Total number of strings in the string vector. 
                          logk --> To traverse through each alphabet in 1 string
                          k logk --> To perform sorting for 1 string 
                          N(k logk) --> To perform the same opertaion for every element in the string vector. 
                          
*********************************************************************************************************/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
  
        unordered_map<string,vector<string> > mymap; //map is created with key value as string, and value as a vector of string
        int n = strs.size(); //Size of the string is stored in 'n'
        string temp; //Store the original element before sorting 
        
        for(int i =0;i<n;++i) //To visit all the string in the vector of the string which is given 
        {
            //Original string which is given is stored in a variable called temp
            temp = strs[i]; 
            
            // sorting the paritcular string
            // After sorting, all the anagrams would have the same key 
            //so, when pushing the key and the value in the map, the string with same key will only push its value element to the map
            sort(strs[i].begin(),strs[i].end()); 
            
            //strs[i] ----> Key in our map  // temp ----> value in our map
            //In map, if we want to store one element as key and vector of element as value, then do this.
            //Syntax:map_name[key].push_back(value);
            mymap[strs[i]].push_back(temp); 
            
            //After this we will have all the Anagrams grouped together in the map which will have both key and the value. 
        }
        
        //Here, we have to output only the Value part from the Map
        
        vector<vector<string> > result; //Create a vector to store only the value part from the map
        
        for(auto itr=mymap.begin();itr!=mymap.end();++itr) //Loop through the map
            result.push_back(itr->second); //Push the value part into the "result" vector
        
        return result; // Return the result 
    }
};
