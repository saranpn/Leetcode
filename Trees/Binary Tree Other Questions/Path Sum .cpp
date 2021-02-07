class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) 
    {
        if(root==NULL) return false; //Base Case
        
        //If it is a leaf node and the target-root's val == 0, the return true, meaning we found the sum 
        if(root->left == NULL && root->right == NULL && targetSum-root->val==0)
            return true; 
        
        //If it is not a leaf node, then call the left sub tree and right sub tree recursively.
        return hasPathSum(root->left,targetSum-root->val) || hasPathSum(root->right,targetSum-root->val);
    }
};

//22-5 = 17            //22-5 = 17
//17-4 = 13            //17-4 = 13
//13-11 = 2            //13-11 = 2
//2-7   = -5           //2-2   = 0    

