//Author: Saravana Kumar
//Source: https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

/* iven an array where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example:

Given the sorted array: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5
 
 *******************************************************************************************************************/


/* IDEA: --> Since it is a sorter array, For binary search tree, the root would be the middle element in the array. 
         --> Create a separate function with the array and with two pointers. 
         --> Totally we need three pointers start, end and middle. 
         --> The idea is to find the middle value of the arrray and store that as root by creating a tree
         and insert all the elements which is on the left side of the array as left subtree 
         and insert all the elements which is on the right side of the array as right subtree 
         by recursively calling that created function. */ 
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

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {
        if(nums.empty()) return 0; //if the array has no element then simply return 
        
        //call a new function by passing array and two extra pointers 
        // start would be 0 and end would nums.size()-1 
        return RecursiveSol(nums, 0, nums.size()-1); 
    }
    
    //Function to create a binary search tree from sorted array by passing the required parameters
    TreeNode* RecursiveSol(vector<int> &nums, int start, int end) 
    {   
        //Note: start, end, middle are used for index value to access the array. 
        
        if(start > end) return 0; //if start index crosses and become greater that end then return 0; 
        
        int middle = start + (end - start + 1) / 2;  //middle value changes for every call 
        
        TreeNode* root = new TreeNode(nums[middle]); // create a root node 
        root -> left = RecursiveSol(nums, start, middle-1); //assign the left nodes
        root -> right = RecursiveSol(nums, middle+1, end); //assign the right nodes 
        
        return root; //return the root node
     }
};
