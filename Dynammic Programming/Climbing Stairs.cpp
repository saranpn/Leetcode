//Dynammic Programming: Bottom Down Approach
//Fibonacci Approach 

class Solution {
public:
    int climbStairs(int n) 
    {
        vector<int> result;
        
        a.push_back(1); //For 1 step
        a.push_back(2); //For 2 step
        
        for(int i=2;i<=n-1;i++)
        {
            a.push_back(a[i-1]+a[i-2]);
        }
        
        return a[n-1];
    }
};
