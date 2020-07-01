class Solution {
public:
    int findDuplicate(vector<int>& nums) 
    {
        unordered_map<int,int> MyMap;
        
        for(int i=0; i<nums.size(); i++)
        {
            MyMap[nums[i]] ++;
            
            if(MyMap[nums[i]] > 1 )
                return nums[i];
        }
        
        return -1; 
    }
};
