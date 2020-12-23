//Simple Binary Search 

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        vector<int> result(2);
        
        int left = 0;
        int right = numbers.size()-1;
        
        while(left<=right)
        {
            int sum = numbers[left] + numbers[right];
            
            if(sum < target) left++;
            
            else if(sum > target) right--;
            
            else if(sum == target)
            {
                result[0] = left+1;
                result[1] = right+1;
                break;
            }
        }
        
        return result; 
    }
};
