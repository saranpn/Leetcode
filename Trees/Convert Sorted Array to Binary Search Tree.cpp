//Time: O(N)
//Space: O(N) 

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {
        if(nums.size() == 0) return {}; //if the array has no element then simply return 
        
        return RecursiveSol(nums,0,nums.size()-1);
    }
    
    TreeNode* RecursiveSol(vector<int> &nums, int start, int end) //Note: start, end, middle are used for index value to access the array.
    {
        //This happens because, when recursive call for right function is called, middle+1 is assigned for start index. 
        //So, at one point start index will become more than end. end is same for all the recursive function for root->right 
        if(start>end) return {};
        
        int middle = start + (end-start+1)/2; //Find the middle element index of the array
         
        TreeNode* root = new TreeNode(nums[middle]); //And assign it to the root 
        root->left = RecursiveSol(nums,start,middle-1); //Assign all the left nodes, by calling the functions recursively from start to middle-1 
        root->right = RecursiveSol(nums,middle+1,end); //Assign all the right nodes, by calling the functions recursively from middle+1 to end
        
        return root;  //return the root node
    }
};
