//Author: Saravana Kumar 
//Source: https://leetcode.com/problems/kth-smallest-element-in-a-bst/

/* Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

 

Example 1:

Input: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
   2
Output: 1

********************************************************************************************************************/

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) 
    {   
        int count = 0; //For index
        int result = 0; //For returning the value
        inorder(root,k,count,result); //using inorder function, since it gives sorted answer
        return result;  //return the result 
    }
    
    void inorder(TreeNode* root, int k, int &count, int &result)
    {   
        if(root == NULL) //if node is null, simply return 
        {
            return; 
        }
        
        //Step 1:
        inorder(root->left,k,count,result); //traversing the left sub-tree
        
        //Step 2:    
        //we keep track how many elements we have visited, since it is a BST and we are also doing inorder traversal, we can stop the traversal once we reach count = kth index 
        count ++; //count t for index, and we are incrementing i
        if(count == k)
        {
            result = root->val; //then simply make result to be that node's val
            return;             //and return it
        }
        
        //Step 3:
        inorder(root->right,k,count,result);  //traversing the right sub-tree 
    }
};
