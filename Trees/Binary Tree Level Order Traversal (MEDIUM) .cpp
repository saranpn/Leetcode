/* Level Order Traversal: Use Queue (BFS) 

--> Create a Queue with node data type and push the root node to the Queue. 
--> Create a 2D Vector (Matrix) to store the result. 
--> Inside the While loop (Until the Queue is not empty) 
            => Create a scalar (for Q size) and Vector (to insert elements into the matrix) 
            => Inside for loop, (condition: Q size) (Processing 1 node: 5 steps) 
                        * Create a pointer of Node type and make it to point it to the front element of the Q 
                        * Push back the element into the Vector. 
                        * Pop out the element from the Q
                        * Push the left child of that node into Q (if there is one)
                        * Push the right child of that node into Q (if there is one) 
                                                        -- exit the for loop 
            => Push back the nums vector into the Matrix 
                                                        -- exit the while loop
--> Finally return the Matrix
                               
 ******************************************************************************************************************************/

/*   Create: 
              Q and Matrix (Outside) 
              Vector and Scalar (inside While loop) 
              Pointer (node data type) (inside for loop) 
              
********************************************************************************************************************************/ 

class Solution {
public:
    vector<vector<int>> result; //Matrix to store the result 
    queue<TreeNode*> MyQueue; //Queue for BFS, with Node datatype 

    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        if (root ==NULL) return {};
        
        MyQueue.push(root); //First push the root node to the queue 
        
        while(!MyQueue.empty()) //Continue until the queue is not empty 
        {
            vector<int> num; //to sotre the value for the node 
            int n = MyQueue.size();
            cout << "n = " << n << endl; //gives you the row size 
            for(int i = 0; i < n; ++i)
            {
                TreeNode* curr = MyQueue.front();
                MyQueue.pop();
                num.push_back(curr->val); 
                for(int i = 0; i<num.size(); i++)
                {
                    cout << "num = "  << num[i] << " ";
                }
                cout << endl;
                if(curr->left != NULL) MyQueue.push(curr->left);
                if(curr->right != NULL) MyQueue.push(curr->right);
            }
            result.push_back(num);
        }
       return result; 
    }
};
