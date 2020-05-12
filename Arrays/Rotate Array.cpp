//Author: Saravana Kumar
//Source: https://leetcode.com/problems/rotate-array/

/************************ IDEA1: Using Extra(another) vector. Time complexity: O(n). Space complexity: O(n) ***************************
Store the last elements in first vector and store first elements in another vector. 
Finally, push back the last elements of first vector inside the another vertor */

class Solution {
    public: 
        void rotate(vector<int>& nums, int k)  //Taking the initial vector and k as parameter
        { 
//If that vector did not have any elemts in it (OR) the k value is less than or equal to zero. Just return and don't do anything

            if ((nums.size() == 0) || (k <= 0)) 
                return;
            
/* We are taking modulus just to reduce the size of k. What does it mean ?? Rotating the array of size 6 with k=2 is same as rotating 
the same array with k=8. Why ?? For k % nums.size() ----> BOTH 2 % 6 and 8 % 6 will be equal to two */
            
            k %= nums.size(); //for reducing the k value
            
//Creating another vector for storing the last elements            
            vector<int> result(nums.begin(), nums.end()-k);
            
//Editing the first vector for storing the first elements
            nums = vector<int>(nums.end()-k, nums.end());

//Pushing back the last elements of first vector inside the another vector.
            for(int i=0; i<result.size(); i++)
                nums.push_back(result[i]);
        }
    };



/************************ IDEA2(BEST): Using Inplace Reverse. Time complexity: O(n). Space complexity: O(1) ***************************
Step 1: Reverse the whole element.
Step 2: Reverese the first elements with respect to k
Step 3: Reverse the last elements with respect to k */

class Solution {
public:
    void rotate(vector<int>& nums, int k) 
    {
        
        if(nums.size() == 0 || k <= 0) return;
        
        k = k % nums.size();
        
        // Step 1: Reverse the whole element.
        reverse(nums.begin(), nums.end());
        // Step 2: Reverese the first elements with respect to k
        reverse(nums.begin(), nums.begin() + k);
        // Step 3: Reverse the last elements with respect to k
        reverse(nums.begin()+k, nums.end());
        
    }
};

