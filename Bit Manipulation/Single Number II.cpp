// Using MAP 

class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        unordered_map<int,int> MyMap; 
        
        for(int i=0; i< nums.size(); i++)
        {
            MyMap[nums[i]]++;
        }
        
        for(auto v: MyMap)
        {
            if(v.second == 1)
            {
                return v.first; 
            }
        }
        
        return 0;
    }
};
