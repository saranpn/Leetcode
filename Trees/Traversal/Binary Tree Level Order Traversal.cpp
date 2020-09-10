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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        //Base case 
        if(root == NULL) return {};
        
        vector<vector<int>> result; //to store the resultant matrix 
        
        queue<TreeNode*> Q;  //Since Level Order Traversal 
        Q.push(root); //push the root element into the Queue
        
        while(!Q.empty())
        {
            vector<int> nums; //To insert elements into the matrix
            int n = Q.size(); //To keep track of Q size 
            
            for(int i=0; i<n; i++)
            {   //Processing the Node: 
                TreeNode* curr = Q.front(); //Create a pointer and make it to point on front element of the Queue
                nums.push_back(curr->val);  //Push that element into the nums vector using that pointer 
                Q.pop();                    //Pop out the element from the Que, (Meaning that we have processed it) 
                
                //Getting ready for another iteration
                if(curr->left !=NULL){ Q.push(curr->left); } //Push the left child of that node into Q (if there is one)
                if(curr->right != NULL){ Q.push(curr->right); } //Push the right child of that node into Q (if there is one) 
            }
            
            result.push_back(nums); //Push back the nums vector into the Matrix, until the Q is not empty 
        }
        return result; //Finally return the final matrix 
    }
};



/************************************************ Only Using Vector **************************************************************
/*  1. Create a Queue and vector(for result) and Push the root node into the queue. 
    2. While the queue is not empty, we need to process each node
    3. Create a pointer of node data type and point it to the front element of the queue 
    4. Push that node's val into the result vector using the pointer 
    4. Pop out the element from the queue 
    5. Push the left and right element of that node into the Q  */ 
    
            queue<TreeNode*> Q;  //Create a Queue (Since Level Order Traversal) 
            vector<int> nums; //Create a vector for Result

            Q.push(root);  //Push the root node into the queue. 

            while(!Q.empty())  //While the queue is not empty, we need to process each node
            {
                TreeNode* curr = Q.front(); //Create a pointer of node data type and point it to the front element of the queue 
                nums.push_back(curr->val);  //Push that node's val into the result vector using the pointer 
                Q.pop();                    //Pop out the element from the queue               

                //Push the left and right element of that node into the Q
                if(curr->left !=NULL){ Q.push(curr->left); } 
                if(curr->right != NULL){ Q.push(curr->right); } 
            }

            //To Print out the result
            for(int i=0; i<nums.size(); i++)
            {
                cout << nums[i] << " ";
            }
