//Time: O(N)
//Space: O(N) 

class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R) 
    {
        //Base Case 
        if(root==NULL) return 0;
        
        int sum = 0; //initializing sum
        sum_function(root,L,R,sum); //calling the sum_function 
        return sum; //Finally return the sum 
    }
        
    void sum_function(TreeNode* root, int L, int R, int &sum)
    {
        if(root->val >=L && root->val <=R) //if root value is between L and R, add root value to sum
        {
            sum = sum + root->val; 
        }

        //Keep calling the left and right child until if it is not null 
        if(root->left != NULL) sum_function(root->left,L,R,sum);
        if(root->right!= NULL) sum_function(root->right,L,R,sum);
    }
};

