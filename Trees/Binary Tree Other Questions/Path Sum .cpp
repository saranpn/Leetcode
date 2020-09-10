class Solution {
private: 

public:
    bool hasPathSum(TreeNode* root, int sum) 
    {
        //Base case 
        if(root == NULL)
            return false;
        
        //If it is a leaf node and the sum
        if(root->left == NULL && root->right == NULL && root->val == sum) 
            return true;
        
        return hasPathSum(root->left, sum-root->val) || hasPathSum(root->right, sum-root->val);
    }
};

//22-5 = 17            //22-5 = 17
//17-4 = 13            //17-4 = 13
//13-11 = 2            //13-11 = 2
//2-7   = -5           //2-2   = 0    

