//LINK: https://www.youtube.com/watch?v=U2PV7-jca2o&t=426s&ab_channel=KeepOnCoding

class Solution {
public:
    bool isValidBST(TreeNode* root) 
    {
         return validate(root, LONG_MIN, LONG_MAX);   
    }
    
    bool validate(TreeNode *root, long min, long max)
    {
        if(root == NULL) return true; 
        
        if(root->val <= min || root->val >= max) return false; 
        
        return validate(root->left, min, root->val) && 
               validate(root->right, root->val, max);
    }
};
