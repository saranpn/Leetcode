//Time: O(N)
//Space: O(1) 

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) 
    {
        int n = digits.size(); //Size of the array 
        
        for(int i=n-1; i>=0; i--) //Traverse from the end to start 
        {
            if(digits[i] != 9) //if digit is not equal to 9
            {
                digits[i]++; //then simply increment that digit
                return digits; //and return the digit 
            }
            else //if the digit is equal to 9, then make digit equals to 0
            {
                digits[i] = 0;
            }
        }    
        
        //This case is only if, all the numbers are 9 
        //Example: 99 --> This will enter the else loop twice and make 00, then we need to add 1 at the beginning to make it 100. 
        //Syntax: vectorName.insert(position, value);
        digits.insert(digits.begin(),1);
        return digits;    
    }
};
