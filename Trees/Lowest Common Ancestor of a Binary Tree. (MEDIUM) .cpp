// https://www.youtube.com/watch?v=Z6d-UM7fDMM&ab_channel=AmellPeralta

class Solution {
public:
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
{
    if(root == NULL || root == p || root == q) 
    {
        return root;
    }
    
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    
    //if(left != NULL && right != NULL) return root;
    
    if(left == NULL) return right; 
    if(right == NULL) return left; 

    return root; //if both left and right are not equal to null 
}
};
