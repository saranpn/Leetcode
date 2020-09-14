//************************************************ SOLUTION 1: In Place Solution ********************************************************************
//Time: O(N) --> For iteration 
//Space: O(1) --> Constant Space 

class Solution {
public:
    int missingNumber(vector<int>& nums) 
    {
        int n = nums.size();
        
        if(n == 0){ return -1};
        
        int TotalSum = (n*(n+1)/2); //This calculates the total sum 
        
        int ArraySum = 0; 
        
        for(int i=0; i<nums.size(); i++)
        {
            ArraySum = ArraySum + nums[i];
        }
        
        return TotalSum - ArraySum;
    }
};



//****************************************************** SOLUTION 2: Using Sorting ********************************************************************
//Time: O(N log N)
//Space: O(1)

class Solution {
public:
    int missingNumber(vector<int>& nums) 
    {
        int n = nums.size();
        
        //Edge Case 1: Empty Array
        if(n == 0) return 0; 
        
        //Edge Case 2: Array of Size 1 
        if(n == 1 && nums[0] == 1) return 0;
        else if(n==1 && nums[0] == 0) return 1;
        
        //Edge Case 3: if the 1st element is not Zero, then simply return 0
        if(nums[left] != 0) return 0;
        
        //Edge Case 4: Normal Case: Sort the array and compare the adjacent elements 
        sort(nums.begin(), nums.end());
        
        int left = 0;
        int right = 1;
        
        while(right<n) //Comparing the adjascent elements 
        {
            
            if(nums[left] == nums[right]-1) //if right is one more than the left, then
            {
                left++;  //increment left 
                right++; //increment right 
            }
            else
            {
                break; //if not, then break the while loop
            }
        }
        return nums[left] + 1; //and return the missing number 
    }
};
