//************************************** SOLUTION 1: INORDER TRAVERSAL - FULL *****************************************************************
//Time: 
//Space: 

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) 
    {
        vector<int> result; 
        inTraverse(root,k, result);
        return result[k-1];
    }
                          
    void inTraverse(TreeNode *root, int k, vector<int>& result)
    {
      if(root == NULL) return ;
        
      inTraverse(root->left, k, result);
      result.push_back(root->val);
      inTraverse(root->right, k,result);
     
    }           
};
