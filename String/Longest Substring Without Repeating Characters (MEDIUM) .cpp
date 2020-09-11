class Solution {
public:
    int lengthOfLongestSubstring(string s) {
         
        int start = 0; //Starting Pointer for sliding window 
        int end = 0;   //End Pointer for sliding window 
        int current_longest = 0; //To get the current longest sub string 
        
        unordered_set<char> MySet; //Create Set, since it stores unique elements
        
        while(end < s.size()) //untill the end pointer reaches last element 
        {
            if(!MySet.count(s[end])) //If the character does not in the set 
            {
                MySet.insert(s[end]); //then, insert the character in set  
                end++;                //and update the end pointer 
                int new_longest = end - start; //Get the new longest sub string 
                current_longest = max(current_longest,new_longest); //Select the maximum between the current longest and new longest substring  
            } 
            else  //If the character already exist in the set (repeated char)
            {
                MySet.erase(s[start]); //then erase the beginning character (Since we need non-repeating character)
                start++; //and update the start pointer 
            }
        }
        return current_longest;  //Finally return the answer 
    }
};
