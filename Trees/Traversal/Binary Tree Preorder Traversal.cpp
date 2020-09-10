class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) 
    {
        //We are creating the result vector outside of the recursive function
        vector<int> result; 
        
        //because, whenever we call a function recursively, result vector is created "freshly" by deleting the previous result vectors with elements. 
        
        //So here result vector should be in 1 function and recursive function should be in another function 
         return preTraverse(root,result);  
    }
    
    vector<int> preTraverse(TreeNode *root, vector<int> &result)
    {
        //untill the root is NOT null we are continuing the process 
        if(root != NULL)
        {
            result.push_back(root->val);
            preTraverse(root->left, result);
            preTraverse(root->right, result);
        }
        
        return result;
    }
};
