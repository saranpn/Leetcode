//********************************************************************************************************************/

//IDEA: Do inorder traversal of the tree and make a count everytime when you reach a node, 
//until k node is reached, then return that node's value. 
      
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
