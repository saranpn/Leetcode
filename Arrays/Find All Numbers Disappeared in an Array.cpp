//Refer link: https://www.youtube.com/watch?v=CTBEcmzLAuA&ab_channel=TerribleWhiteboard

/********************************************************** SOLUTION 1: Using No Extra Space ******************************************
//Time: O(N)
//Space: O(1)

/* IDEA: Traverse the array and mark the element -ve by considering it as an index number. 
         Then traverse the array again, and push the positive elements into the result vector, which would be the answer. 
*/

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> result;
        
        for(int i=0; i<n; i++) //Traverse the array 
        {
            int index = abs(nums[i]) - 1; // -1 is to consider all the elements as index, because index starts from zero. 
            nums[index] = abs(nums[index]) * -1; // And abs is to consider only +ve numbers, since we already changed that to -ve
        }
        
        for(int i=0; i<n; i++) //Traverse the array 
        {
            if(nums[i] > 0) //If a number is +ve 
                result.push_back(i+1); //Then, push i+1, which would be the missing number 
        }
        
        return result; 
    }
};
/********************************************************** SOLUTION 2: Using Hash Set ***************************************************
//Time: O(N)
//Space: O(N)

/* IDEA: Add the elements into the Set
         Then if "i" is not in the Set, then add that to the result
*/

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) 
    {
        set<int> MySet;
        vector<int> result; 
        int n = nums.size();
        
        for(int i=0; i<n; i++)
        {
            MySet.insert(nums[i]);
        }
        
        for(int i=1; i<=n; i++)
        {
            if(!MySet.count(i)) 
                result.push_back(i);
        }
        return result; 
    }
};
