class Solution {
public:
    bool isSubsequence(string sub_string, string string) 
    {
         int i = 0; //pointer for string
         int j = 0; //pointer for sub_string
    
    //Base case 
    if(sub_string.size() == 0 ) 
    { 
        cout << "The sub-array is Empty";
        return true; 
    }
    
    while(i<string.size() && j<sub_string.size()) //loop until one of the strings comes to an end 
    {
        if(sub_string[j] != string[i]) //if the char from sub-string is not equal to string 
        {
            i++; //increment the "i" pointer of the string
        }
        else if(sub_string[j] == string[i]) //if both the char are Equal 
        {
            cout << "Found " << string[i] << endl; 
            j++; //increment the "j" pointer of the sub_string 
            i++; //also increment the "i" pointer of the string
            
            //Sub-Sequence is valid only when j value becomes the size of sub-string (Think yourself of when j value is incremented)
            if(j == sub_string.size()) 
            {
                cout << "Valid"; 
                return true;
            }
        }
    }
    
    //if Not this is not a valid Sub-Sequence
    cout << "Not Valid";
    return false;
    }
};
