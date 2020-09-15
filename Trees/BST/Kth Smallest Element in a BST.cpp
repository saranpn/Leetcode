//************************************** SOLUTION 1: INORDER TRAVERSAL - ONLY UPTO K ELEMENTS  *****************************************************************
//Time: O(N)
//Space: O(k)

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) 
    {
        int result = 0; //To return the result 
        int count = 0; //To make a count of how many minimum elements traversed so far
        inTraverse(root,k, result,count);
        return result;
    }
                          
    void inTraverse(TreeNode *root, int k, int& result, int& count)
    {
      if(root == NULL) return; //Base Case 
        
      //Step 1: Traverse the left subtree deeply till the end   
      inTraverse(root->left, k, result, count);

      //Step 2: After the leaf node of left subtree is reached, it starts counting 
      count++;
      if(count==k) //When the count becomes equal to k, then that element would be the kth smallest element 
      {
        result = root->val; //make result equals to the root's val
        return; //Then return 
      }
       
      //Step 3: To call the right subtree  
      inTraverse(root->right, k,result,count);
     
    }           
};



//************************************** SOLUTION 2: INORDER TRAVERSAL - FULL TRAVERSAL (NOT OPTIMAL) *****************************************************************
//Time: O(N)
//Space: O(N)

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
