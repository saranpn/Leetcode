class Solution {
public:
    int minDepth(TreeNode* root) 
    {
        int minimum_depth = 0;
        
        //if there is no root node
        if(root == NULL) 
        {
            return NULL;
        }
        
        //if there is only root node 
        if(root->left == NULL && root->right == NULL)
        {
            return 1; 
        }
        
        int left_depth = minDepth(root->left); //get the depth of left sub-tree 
        int right_depth = minDepth(root->right); //get the depth of right sub-tree 
        
        //if there is no left OR right subtee, then follow this 
        if(left_depth == 0 || right_depth == 0)
        {
            minimum_depth = max(left_depth,right_depth) + 1;
            return minimum_depth; 
        }
        else //if there is alteast 1 left and right subtree, then follow this 
        {
            minimum_depth = min(left_depth,right_depth) + 1;
            return minimum_depth; 
        }
    }
};
