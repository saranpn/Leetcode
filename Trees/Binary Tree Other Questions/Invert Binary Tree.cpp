/* Given: 

     4
   /   \
  2     7
 / \   / \
1   3 6   9

After 1st Iteration: 

     4
   /   \
  7     2
 / \   / \
6   9 1   3

After 2nd Iteration:

     4
   /   \
  7     2
 / \   / \
9   6 3   1  

Inverted Fully */


//*********************************************************** Using Recursion ***************************************************************************************

//TIME: O(N) (Since we are visiting all the nodes in the tree) 
//SPACE: O(depth) = O(log N)
         Because we using Call stack. Here the call stack depends on the depth of the tree. Because that is longest recursive call we can make.
         
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) 
    {
        //Base Case
        if(root == NULL)  return root;
        
        //swap(root->left,root->right);
        
        TreeNode* tempLeftNode = root->left;
        root->left = root->right;
        root->right = tempLeftNode;
        
        //Recursive calls 
        invertTree(root->left); 
        invertTree(root->right);
        
        return root;
    }
};

//*********************************************************** Using BFS ***********************************************************************************************

//TIME: O(N) (Since we are visiting all the nodes in the tree) 
//SPACE: O(N) (Since we are using Queue) 

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) 
    {
        //Base Case
    if(root == NULL) return root; 

     queue<TreeNode*> Q;  //Create a Queue 

     Q.push(root);  //Push the root node into the queue. 

     while(!Q.empty()) //While the queue is not empty, we need to process each node
     {
         TreeNode* curr = Q.front();  //Create a pointer of node data type and point it to the front element of the queue
         swap(curr->left,curr->right);// Swap the left child and right child of that Node 
         Q.pop();                     ////Pop out the element from the queue 
         
        //Then, Push the left and right child of that node into the Q 
         if(curr->left !=NULL){ Q.push(curr->left); } 
         if(curr->right != NULL){ Q.push(curr->right); } 
     }

    return root; 
    }
};



