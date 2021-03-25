class Solution {
public:
    bool isSubsequence(string s, string t) 
    {
        int n = s.size(); //sub-string size
        int m = t.size(); //string size
        
        int sub_s1 = 0; //pointer for sub-string
        int s2 = 0; //pointer for string
        
        //Base Case:
        if(n==0) return true;
        
        while(sub_s1<n && s2<m) //loop until one of the strings comes to an end 
        {
            //Case 1: If the char are Not-Equal, Increment String pointer 
            if(s[sub_s1] != t[s2]) 
                s2++;
            
            //Case 2: If the char are Equal
            else
            {
                sub_s1++; //Increment Sub-String Pointer 
                s2++; //Increment String Pointer 
                
                if(sub_s1 == n) //If everything is fine, at one point Sub_string pointer number will be same as the size of the sub-string
                    return true;  //Return True 
            }    
        }
        
        return false; //if Not this is not a valid Sub-Sequence, return false 
    }
};
