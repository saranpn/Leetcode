class Solution {
public:
    TreeNode* mergeTrees(TreeNode *t1, TreeNode *t2) 
    {
        if(t1 == NULL && t2 == NULL) return {}; //if both trees are Null, then return empty set
        if(t1 == NULL) return t2; //Case 1 
        if(t2 == NULL) return t1; //Case 2 
        
        //Case 3 (if we have atleast 1 node in both trees)
        
        t1->val = t1->val + t2->val; //Take the value from t2 and add it to the t1
        
        //Go to left subtrees of both the trees and call recursively, and then store the  that in t1-> left, which will be used for next call. 
        t1->left = mergeTrees(t1->left,t2->left);
        
        //Similarly for right subtrees of both the trees
        t1->right = mergeTrees(t1->right,t2->right);
        
        return t1;   
    }
};
