// Author: Saravana Kumar
// Source: https://leetcode.com/problems/symmetric-tree/submissions/

/* Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
 

But the following [1,2,2,null,3,null,3] is not:

    1
   / \
  2   2
   \   \
   3    3
 

Follow up: Solve it both recursively and iteratively. */ 

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
 
/************************************* RECURSIVE APPROACH *************************************************
Time Complexity: O(N) --> Since we need to check all the nodes in the Tree to tell if it is symmetric or not i.e. n nodes. 
Space Complexity: O(height) --> Because we are doing the height traversal. So the call stack is proportional to the height of the tree, 
                                and not proportional to the number of nodes */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        //Case 1: Base Case
        if(root == NULL)  return true;
        
        return check(root->left,root->right);
    }
        
private:
    bool check(TreeNode *leftSub, TreeNode *rightSub) //This function takes 
    {
        //Case 2: if there is only root node, then return true
        if(leftSub == NULL && rightSub == NULL) return true;  
        
        //If there are both left and right subtrees 
        else if(leftSub != NULL && rightSub != NULL) 
        {  
        
            //Check if its value matches
            return leftSub->val == rightSub->val && 
            //if the value matches, go for next. That is, left node's left child should match the right node's right child
                   check(leftSub->left, rightSub->right) && 
            //and left node's right child should match the right node's left child
                   check(leftSub->right, rightSub->left);
        }
       
        //If it doesn't enter both of the if statements above, it means the left and right sub has different values, hence its not symmeteric
        return false;  //thererfore return false. 
    }
};

