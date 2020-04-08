//AUTHOR: Saravana Kumar
//Source: https://leetcode.com/problems/n-ary-tree-preorder-traversal/submissions/

/************************************************************************************************

Given an n-ary tree, return the preorder traversal of its nodes' values.

Nary-Tree input serialization is represented in their level order traversal, each group of children is separated by the null value (See examples).

*************************************************************************************************/

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

class Solution 
{  //Define this function in private: Why ?? 
    void traversal_preorder(Node *root, vector<int> &result) //Define the traversal_preorder function with *root and &result as parameters
    {
        if(root == NULL) //Can also be written as if(!root) return;
        {
            return;
        }
        
        result.push_back(root -> val); //insert the data
        
        for(int i=0; i< root->children.size(); i++)
            traversal_preorder(root->children[i], result); //Recursively calling its function by passing children as parameter to the root
    }
public:
    vector<int> preorder(Node* root) 
    {
        vector<int> result; //Create a vector to store the result
        
        traversal_preorder(root, result); //Call the traversal_preorder function with root and result as parameter
            
        return result;  // return the result
    }
};
