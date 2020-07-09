class Solution {
public:
    bool repeatedSubstringPattern(string s) 
    {
        vector<int> result(26,0);
        
        int temp1 = 0;
        
        for(int i=0; i<s.size(); i++)
        {
            temp1 = s[i] - 'a';
            
            if(result[temp1] == 0)
            {
                temp1 = s[i] - 'a';
                result[temp1]++;
            }
            else
            {
                result[temp1]--;
            }      
        }
        
        for(int k=0; k<result.size(); k++)
        {
            if(result[k] != 0)
            {
                return false;
            }
        }
        
        return true;
    }
};
