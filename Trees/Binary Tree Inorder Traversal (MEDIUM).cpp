//Author: Saravana Kumar  
//Source: https://leetcode.com/problems/binary-tree-inorder-traversal/
/* Given a binary tree, return the inorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,3,2]
Follow up: Recursive solution is trivial, could you do it iteratively? */


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
 
 
//******************************************** RECURSIVE VERSION ******************************************************* 
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inorder(root, result);
        return result;
    }
private:
    void inorder(TreeNode* root, vector<int>& result) 
    {
        if (root==NULL) {
            return; 
            }
    /*
        This return means 3 things:
        
        case 1: if there are other commands below the recursive call, then go and complete that.
        case 2: if there are no commands after the recursive call, then go back to the previous recursive call and complete left over commands. 
        case 3: if there are no commands after the recursive call, and all the previous recursive calls has been finished, then exit "only" exit the function
        
    */
        inorder(root -> left, result);
        result.push_back(root -> val);
        inorder(root -> right, result);
    }
};

