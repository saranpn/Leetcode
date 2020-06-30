class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        unordered_map<int,int> MyMap;
        
        for(int i=0; i<nums.size(); i++)
        {
            MyMap[nums[i]] ++;
            
            if(MyMap[nums[i]] > nums.size()/2 )
                return nums[i];
        }
        
        return -1; 
    }
};
