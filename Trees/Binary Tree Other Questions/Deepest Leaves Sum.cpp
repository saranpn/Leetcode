class Solution {
public:
    int deepestLeavesSum(TreeNode* root) 
    {
        if(root==NULL) return 0;
        
        queue<TreeNode*> Q;
        Q.push(root);
        
        int sum = 0;
        
        while(!Q.empty())
        {
            sum = 0;
            int n = Q.size();
       
            for(int i=0; i<n; i++)
            {
                TreeNode* curr = Q.front();
                sum = sum + curr->val;
                Q.pop();    
                
                if(curr->left!=NULL) Q.push(curr->left);
                if(curr->right!=NULL) Q.push(curr->right);
            }
        }
        return sum; 
    }
};
