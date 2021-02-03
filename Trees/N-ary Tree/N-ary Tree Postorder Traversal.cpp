//Author: Saravana Kumar
//Source: https://leetcode.com/problems/n-ary-tree-postorder-traversal/

/********************************************************************************************************
Given an n-ary tree, return the postorder traversal of its nodes' values.

Nary-Tree input serialization is represented in their level order traversal, each group of children is separated by the null value (See examples).

*********************************************************************************************************/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

//***********************************************  RECURSIVE SOLUTION **********************************************

class Solution 
{
    void traversal_postorder(Node *root, vector<int> &result) //Define the traversal_postorder function with *root and &result as parameters
    {
        if(!root) return;
        
        for(int i=0; i<root->children.size(); i++)
        {
            traversal_postorder(root->children[i], result); //Recursively calling its function by passing children as parameter to the root
        }
        
        result.push_back(root -> val);  //insert the data to the vector

}
    
    
public:
    vector<int> postorder(Node* root) 
    {
        vector<int> result;   //Create a vector to store the result
        
        traversal_postorder(root, result); //Call the traversal_postorder function with root and result as parameter
        
        return result;   // return the result
    }
};
