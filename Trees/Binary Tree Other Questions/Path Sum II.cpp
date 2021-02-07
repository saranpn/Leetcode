class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) 
    {
        vector<vector<int>> res; //Result Matrix
        
        vector<int> temp; //Vector to insert into the Matrix
        
        pathSumHelper(root, res, temp, sum); 
        
        return res;
    }
    
    void pathSumHelper(TreeNode* root, vector<vector<int>>& res,vector<int> temp, int sum)
    {
        if(root == NULL) return; //Base Case
        
        temp.push_back(root->val); //Push root's val into temp vector 
        
        //If leaf Node
        if(root->left == NULL && root->right == NULL)
        {
            //and if the sum-root's val = 0, then push that vector into the Matrix
            if(sum-root->val == 0)
                res.push_back(temp);
            
            //If not, then remove that leaf node from the vector (Becuase that's not the answer)
            temp.pop_back();
            return;
        }
        
        //If not Leaf Node, then call the left and right sub-tree iteratively 
        pathSumHelper(root->left, res, temp, sum-root->val);
        pathSumHelper(root->right, res, temp, sum-root->val);
    }
};
