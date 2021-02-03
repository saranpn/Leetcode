//SOURCE: https://www.youtube.com/watch?v=M_BaOHkTtyY&ab_channel=Errichto

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution 
{
    //(diameter,depth)
    pair<int,int> diameter(TreeNode* root)   
    {
        if(root==NULL)  return{0,0};

        
        pair<int,int> left = diameter(root->left); //Diameter of left sub-tree
        pair<int,int> right = diameter(root->right); //Diameter of right sub-tree 
        
        //max(diameter of left node, diameter of right node, Sum of depth of both left and right)
        int diam = max({left.first, right.first, left.second+right.second});
        return {diam, max(left.second, right.second) + 1};
    }
    
public:
    int diameterOfBinaryTree(TreeNode* root) 
    {
        return diameter(root).first;    
    }
};
