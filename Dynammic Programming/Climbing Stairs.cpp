//Dynammic Programming: Bottom Down Approach
//Fibonacci Approach 

class Solution {
public:
    int climbStairs(int n) 
    {
        vector<int> result;
        
        result.push_back(1); //For 1 step
        result.push_back(2); //For 2 step
        
        for(int i=2;i<=n-1;i++)
        {
            result.push_back(result[i-1]+result[i-2]);
        }
        
        return result[n-1];
    }
};
