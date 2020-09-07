//Author: Saravana Kumar 
//Source: https://leetcode.com/problems/maximum-depth-of-binary-tree/submissions/

/* Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Note: A leaf is a node with no children.

Example:

Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
return its depth = 3.

***************************************************************************************************************/

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

// IDEA:  Using Recursion go and find the maximum depth of the left subtree and right subtree and add 1 (for root node) and return the value. 

class Solution {
public:
    int maxDepth(TreeNode* root) 
    {
        int depth = 0; //initiailize the depth variable 
        
        if(root == NULL) // if there is no root node, then no tree
        {
            return depth; //Then return the depth as zero 
        }
        
        int left_depth = maxDepth(root->left);
        int right_depth = maxDepth(root->right);
        // How deep is you left subTree and How deep is your right subTree. And once we know that, we take the maximum depth from them and 1 to include ourself
        
        /* First maxDepth(root->left) will find the maximum depth of the left subtree and put it into 1st element in the max function and 
        then, maxDepth(root->right) will find the maximum depth of the right subtree and put it into 2nd element in the max function
        then, it will give the maximum value and it will be added to 1 to include the root element and the final value is stored in depth */
        
        depth = 1 + max(left_depth,right_depth); 
        
        return depth; //return the max depth of the binary tree 
    }
};
