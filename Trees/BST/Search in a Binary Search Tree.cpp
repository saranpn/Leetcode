//*************************************** SOLUTION 1: RECURSIVE METHOD ***************************************************
// TIME: O(N)
// SPACE: O(1) 

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) 
    {
        if(root==NULL) return {}; //Return NULL or empty set if root is NULL
        
        if(root->val == val) return root; //Returns the whole root with subtree(if any) if it finds the number
        
        else if(root->val < val) //if the root value is less than target value,
            return searchBST(root->right, val); //then move to right subtree and repeat the function 
        
        else                                    //if the root value is greater than target value,
            return searchBST(root->left, val);  //then move to left subtree and repeat the function 
    }
};
 
