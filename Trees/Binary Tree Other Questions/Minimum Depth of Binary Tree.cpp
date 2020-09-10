class Solution {
public:
    int minDepth(TreeNode* root) 
    {
        //Case 1: Base Case
        if(root == NULL) return 0; 
        
        //Case 2: Only root node 
        if(root->left == NULL && root->right == NULL) return 1; 
        
        //Calculate  the depth of both subtrees 
        int left_subTree = minDepth(root->left);
        int right_subTree = minDepth(root->right);
        
        int depth = 0; //initialize the depth 
        
        //Case 3: Only Left SubTree or Right SubTree: Then max and min depth would be the same
        if(root->left == NULL || root->right == NULL) 
        {
            depth = max(left_subTree,right_subTree) + 1; 
        }
        
        else //Case 4: If both left and right subtree are present. 
        {
            depth = min(left_subTree,right_subTree) + 1;
        }
         
        return depth; //Finally return the depth 
    }
};
