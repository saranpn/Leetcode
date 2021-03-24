// ********************************************************** ONE PASS SOLUTION ***********************************************************************
/* IDEA: Move all the Zeros to the front, and move all the Twos to the back, and then the Ones will automatically end up in the middle 

3 Pointers: i ----> For Zero (Starts from Beginning of the Array)
            j ----> For Two (Starts from End of the Array)
          ptr ----> Common Pointer (Starts from End of the Array)
          
 If, nums[i] == 0 --------> Swap i and ptr
 If, nums[j] == 2 --------> Swap j and ptr
 else,            --------> Decrement ptr 

*/

class Solution {
public:
    void sortColors(vector<int>& nums) 
    {
        int i = 0; //Pointer for Zero
        int j = nums.size()-1; //Pointer for Two
        
        int ptr = j; //Common pointer 
        
        while(i<=ptr)
        { 
            if(nums[ptr] == 0) //When Common pointer is Zero
            {   //Put Zeros to the front
                swap(nums[i],nums[ptr]); //Then swap Zero and Common Pointer
                i++; //Increment Zero Pointer
            }
            
            else if(nums[ptr] == 2) //When Common pointer is Two
            {   //Put Twos to the back 
                swap(nums[j],nums[ptr]); //Then swap Two and Common Pointer  
                j--; //Decrement Two Pointer
                ptr--; //Decrement Common Pointer 
            }
            else //Means if One
            {
                ptr--; //Decrement Common Pointer 
            }
        }
    }
};



//************************************************************** TWO PASS SOLUTION **********************************************************

class Solution {
public:
    void sortColors(vector<int>& nums) 
    {
        int n = nums.size();
        int ZeroCount = 0;
        int OneCount = 0;
        int TwoCount = 0;
        
        for(int i=0; i<n; i++)
        {
            if(nums[i]==0) ZeroCount++;
            else if(nums[i]==1) OneCount++;
            else if(nums[i]==2) TwoCount++;
        }
        
        for(int i=0; i<n; i++)
        {
            if(ZeroCount > 0)
            {
                nums[i] = 0;
                ZeroCount--;
            }
            
            else if (OneCount > 0)
            {
                nums[i] = 1;
                OneCount--;
            }
            
            else if(TwoCount > 0)
            {
                nums[i] = 2;
                TwoCount--;
            }
        }
    }

};
