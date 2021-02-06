class Solution {
public:
    void flatten(TreeNode* root) 
    {
        //Base Case 
        if(root==NULL) return; 
        
        //Only root, and no left and right subtree
        if(root->left == NULL && root->right == NULL) return;
        
        if(root->left != NULL)
        {
            flatten(root->left); //Pass the left child of the root 
            
            TreeNode* temp = root->right; //store the right child in temp pointer (Original root right stored here)
            root->right = root->left; // root's left will now become root's right  (Original root left stored here)
            root->left = NULL; //Then, set the root's left to NULL 
            
            /* Pointer is at 2                                                      Pointer is at 1 
            
               temp = 4;                                                            temp = 5; (Has both 5 and 6)
               root->right = 3;                                                     root->right = 2; (All 2,3 and 4)
               root->left = NULL;                                                   root->left = NULL;
            
                           1                                                              1                                           
                          /                                                                \
                         2                                                                  2   
                          \                                                                  \
                           3   (3 shifted to right side )                                     3
                                                                                               \
                                                                                                4
            */ 
            
            TreeNode* curr = root->right; //Take another pointer to traverse through extreme right 
            
            while(curr->right != NULL) //traverse through the extreme right
            {
                curr = curr->right;
            }
            
            curr->right = temp; //And then put temp variable to the right side
            
            /*
                    1
                   /
                  2
                   \
                    3
                     \
                      4
            */
        }
        
        flatten(root->right);

    }
};
