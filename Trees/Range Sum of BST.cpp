//Author: Saravana Kumar  
//Source: https://leetcode.com/problems/range-sum-of-bst/ 

/*******************************************************************************************
Given the root node of a binary search tree, return the sum of values of all nodes with value between L and R (inclusive).

The binary search tree is guaranteed to have unique values.

 

Example 1:

Input: root = [10,5,15,3,7,null,18], L = 7, R = 15
Output: 32
Example 2:

Input: root = [10,5,15,3,7,13,18,1,null,6], L = 6, R = 10
Output: 23

***************************************************************************************************/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
int rangeSumBST(TreeNode *root, int L, int R)
{
    int sum = 0;
    
    Add_Full_Nodes(root, &sum, L, R);
    
    return sum;
}

void Add_Full_Nodes(TreeNode *root, int *sum, int L, int R)
{
    if(root == NULL) //if root is null return nothing
        return;
    if(root -> val >= L && root -> val <= R) //if root value is between L and R, add root value to sum
        *sum = *sum + root -> val;
    if(root -> left != NULL) //if left child of root is not null, then call the same function by passing left child as root value and then add it to the sum
        Add_Full_Nodes(root->left, sum, L, R);
    if(root -> right != NULL)//if right child of root is not null, then call the same function by passing right child as root value and then add it to the sum
        Add_Full_Nodes(root->right, sum, L, R);
    return;
}
};


