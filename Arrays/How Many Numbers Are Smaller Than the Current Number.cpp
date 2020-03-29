class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        
        vector<int> output;
        
        for(int i=0; i<nums.size(); i++)
        {
            int k = 0;
            
            //For every i, j starts comparing from first value in the array
            for(int j=0; j<nums.size(); j++) 
            {
                if (nums[j] != nums[i] && nums[j] < nums[i])
                    k++ ;
            }
            
            output.push_back(k);
            
        }
        
        return output;
}
};

