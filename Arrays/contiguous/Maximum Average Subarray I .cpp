class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) 
    {
        int n = nums.size();
    
        double currAvg = 0; //to store the currAvg of the subarray 
        double maxAvg = 0; //to store the max
        
        int start = 0; 
        double sum = 0; 
        
        for(int i=0; i<n; i++)
        {
            sum = sum + nums[i]; //Caluculate the sum for k elements 
            
            if(i >= k-1) //After we reached k elements 
            {
                currAvg = sum/k; //Calculate the avg for those k elements 
                maxAvg = max(currAvg, maxAvg); //then select the maximum number between currAvg and maxAvg 
                sum = sum - nums[start]; //Then, subtract the starting element from the sum
                start++; //And increment the start pointer 
            }
        }
        return maxAvg;  //Finally return the maxAvg 
    }
};
