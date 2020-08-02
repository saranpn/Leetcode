//*************************************** SOLUTION 1: Brute Foce Method ********************************************************
// TIME COMPLEXITY: O(N) --> Where N is the number of characters in the array. We iterate through the all the characters only once. 
// SPACE COMPLEXITY: O(1) --> We are not stroring any extra spaces here. 

class Solution {
public:
    bool detectCapitalUse(string s) 
    {
        int word1 = 0;
        int word2 = 0;
        int word3 = 0;
    
        //base case 
        if(s.size()==0 || s.size()==1)
        {
            cout << "True";
            return true;
        }
        
        //Iterate through the string
        for(int i=0; i<s.size(); i++)
        { 
            //For word 1 case --> Example: Go, Leetcode 
            if(isupper(s[0]) && !isupper(s[1]))
            {
                if(i>0)
                {
                    if(word1 == s.size() && islower(s[s.size()-1]))
                    {
                        cout << "True, 1st letter is upper case and all others are lower case";
                        return true;
                    }
                    else if(islower(s[i]) && isupper(s[0]))
                    {
                        word1 ++;
                    }
                    else
                    {
                        cout << "False, upper case letter found in between";
                        return false;
                    }
                }
            }
    
            //For word 2 case --> Every letter is lower. Example: sad, hello 
            else if(islower(s[0]))
            {
                if(word2 == s.size())
                {
                    cout << "True, No Upper Case letters" << endl;
                    return true; 
                }

                else if (!isupper(s[i]))
                {
                    word2 ++;
                }

                else 
                {
                    cout << "False, Upper Case letter found in between";
                    return false;
                }
            }
        
            //For word 3 case. Every letter is upper case --> Example: USA, PAN
            else if(isupper(s[0]))
            {
                if (word3 == s.size())
                {
                    cout << "True, All are Upper Case letters" << endl;
                    return true; 
                }

                else if(!islower(s[i]))
                {
                    word3 ++;
                }

                else
                {
                    cout << "False, A lower case letter found in between the upper case letters";
                    return false; 
                }
            }
    }     
        return true;
    }
};
