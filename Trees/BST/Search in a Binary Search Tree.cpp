//Author: Saravana Kumar 
//Source: https://leetcode.com/problems/search-in-a-binary-search-tree/discuss/?currentPage=1&orderBy=most_votes&query=c%2B%2B

/********************************************************************************************************************************

Given the root node of a binary search tree (BST) and a value. You need to find the node in the BST that the node's value equals the given value. Return the subtree rooted with that node. If such node doesn't exist, you should return NULL.

For example, 

Given the tree:
        4
       / \
      2   7
     / \
    1   3

And the value to search: 2
You should return this subtree:

      2     
     / \   
    1   3
    
 *********************************************************************************************************************************/
 
 /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 
*/

// Here, val ---> is the value we want to search
//       root->val ---> is the data value of the particular root node 

/*************************************** RECURSIVE METHOD ***************************************************/

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
 
