class Solution {
public:
 string longestCommonPrefix(vector<string> &strs) 
 {
        string prefix = ""; //Create a string with empty prefix
     
       //Base Case: if the given string is empty, then return the empty prefix 
        if(strs.empty()) return prefix; 
     
        //Here we are taking the first character of every index and comparing
        // That is the reason "j" comes first before "i"
     
        for(int j = 0; j < strs[0].size(); j++)
        {
            for(int i = 1; i < strs.size(); i++)
            {
                if(strs[i][j] != strs[0][j])  //if the first characters didn't match
                   return prefix; //then return the prefix we obtained so far 
            }
            prefix = prefix + strs[0][j]; //Add the char to the prefix, if all are equal
        }
        return prefix; //Finally return the prefix we got 
    }
};
