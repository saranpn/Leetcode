class Solution {
public:
    bool detectCapitalUse(string s) 
    {
    int count0 = 0;
    int count = 0;
    int count1 = 0;
    int i = 0;
        
    if(s.size()==0 || s.size()==1)
    {
        cout << "True";
        return true;
    }
    
    for(int i=0; i<s.size(); i++)
    { 
        if(isupper(s[0]) && !isupper(s[1]))
        {
            if(i>0)
            {
            if(count0 == s.size() && islower(s[s.size()-1]))
            {
                cout << "True, 1st letter is upper case and all others are lower case";
                return true;
            }
            else if(islower(s[i]) && isupper(s[0]))
            {
                count0 ++;
            }
            else
            {
                cout << "False, upper case letter found in between";
                return false;
            }
            }
        }
        
        else if(islower(s[0]))
        {
            if(count == s.size())
            {
                cout << "True, No Upper Case letters" << endl;
                return true; 
            }
            
            else if (!isupper(s[i]))
            {
                count ++;
            }
            
            else 
            {
                cout << "False, Upper Case letter found in between";
                return false;
            }
        }
        
        else if(isupper(s[0]))
        {
            if (count1 == s.size())
            {
                cout << "True, All are Upper Case letters" << endl;
                return true; 
            }
            
            else if(!islower(s[i]))
            {
                count1 ++;
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
