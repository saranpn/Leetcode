class Solution {
public:
    int findDuplicate(vector<int>& nums) 
    {
        int n = nums.size();
        
        unordered_map<int,int> MyMap;
        
        for(int i=0; i<n; i++)
        {
            MyMap[nums[i]]++;
        }
        
        for(auto v : MyMap)
        {
            if(v.second >= 2)
            {
                return v.first;
            }
        }
        
        return 0;
    }
};
