
//************************************************************* BRUTE FORCE METHOD **************************************************************************
class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) 
    {
        if(root1 == NULL && root2 == NULL) return {};
        
        vector<int> result; 
        
        Tree1Search(root1,result);
        Tree2Search(root2,result);
        
        sort(result.begin(),result.end());
        
        return result;
    }
    
    
    void Tree1Search(TreeNode* root1, vector<int> &result)
    {
        if(root1 != NULL)
        {
            Tree1Search(root1->left,result);
            Tree1Search(root1->right,result);
            result.push_back(root1->val);
        }
    }
    
    void Tree2Search(TreeNode* root2, vector<int> &result)
    {
        if(root2 != NULL)
        {
            Tree2Search(root2->left,result);
            Tree2Search(root2->right,result);
            result.push_back(root2->val);
        }
    }
};
