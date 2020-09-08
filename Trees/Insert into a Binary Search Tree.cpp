/* IDEA: 
          Given the tree:
        4
       / \
      2   7
     / \
    1   3
    
And the value to insert: 5

Iteration 1: --> Here root is Not Null.
             --> Here root->val is less than the val (4 < 5)
                So, this will go inside else part. 
                Call the Function iteratively, by passing the root->right (7) as parameter. 
                
 Iteration 2: --> Here root is Not Null.
              --> Here root->val is greater than the val (7 > 5)
                  So, this will go inside if part. 
                  Call the Function iteratively, by passing the root->left (NULL) as parameter. 
                  
 Iteration 3: --> Here root is NULL. 
              --> So this enter the first if condition.
                  And this will create a node and insert the val into that node. 
                  
 *****************************************************************************************************************************/

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) 
    {
        if(root == NULL) return new TreeNode(val);
        
        if(root->val > val) {
            root->left = insertIntoBST(root->left, val);
        }
            
        else {
            root->right = insertIntoBST(root->right, val);
        }
        
        return root;
    }
};
