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
// Time Complexity: O(N) --> Since we are visiting all the nodes in the tree
// Space Complexity: O(N) --> We are making function call stack 
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

//*********************************************** ITERATIVE APPROACH *************************************************************
// Time Complexity: O(N) --> since we are visiting every node in the tree
// Space Complexity: O(N) --> Since we are using stack and we are storing all the nodes in the tree to the stack 

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int> result; //to return the result vector
        
        stack<TreeNode*> StackIn; //create a stack (LIFO)
        
        while(true)  //the condition to break the while is given inside the while loop
        {
            if(root != NULL) //if the root is not NUll, then enter this if condition
            {
                StackIn.push(root); //push that root into stack 
                root = root-> left; //make root to point on root's left 
            }
            else
            {  //while condition breaks only when the root is null and when the stack is empty
                if(StackIn.empty()) { break; }  
                
                root = StackIn.top(); //make stack's top equal to root
                StackIn.pop(); //pop out that top element
                result.push_back(root->val); //store that root's val in result vector
                root = root -> right; //make root to point on root's right 
            }
        }
        
        return result; //return the result
    }
};
