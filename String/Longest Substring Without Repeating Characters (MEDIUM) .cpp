class Solution {
public:
    int lengthOfLongestSubstring(string s) {
         
        int start = 0; //Starting Pointer for sliding window 
        int end = 0;   //End Pointer for sliding window 
        int ans = 0;   //To store the answer 
        
        unordered_set<char> MySet; //Create Set, since it stores unique elements
        
        while(end < s.size()) //untill the end pointer reaches last element 
        {
            if(!MySet.count(s[end])) //If the character does not in the set 
            {
                MySet.insert(s[end]); //then, insert the character in set  
                end++;                //and update the end pointer 
                ans = max(ans,end-start); //Check if the new distance is longer that the current answer. If yes, then replace that with current answer. 
            } 
            else  //If the character already exist in the set (repeated char)
            {
                MySet.erase(s[start]); //then erase the beginning character (Since we need non-repeating character)
                start++; //and update the start pointer 
            }
        }
        return ans;  //Finally return the answer 
    }
};
