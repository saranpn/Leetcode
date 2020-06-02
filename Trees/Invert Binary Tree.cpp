/* Invert a binary tree.

Example:

Input:

     4
   /   \
  2     7
 / \   / \
1   3 6   9

******************************************************************************************/

//REFER: https://www.youtube.com/watch?v=2zLM6K1RItQ
  
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) 
    {
        if(root == NULL) 
        { 
            return root;
        }
        
        TreeNode* tempLeftNode = root->left;
        root->left = root->right;
        root->right = tempLeftNode;
        
        invertTree(root->left);
        invertTree(root->right);
        
        return root;
    }
};
