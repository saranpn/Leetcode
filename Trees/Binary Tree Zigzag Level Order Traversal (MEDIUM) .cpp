class Solution {
    
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
    //Base case 
    if(root == NULL) return {};

    vector<vector<int>> result; //to store the resultant matrix 

    deque<TreeNode*> Q;  //Since Zigzag Traversal 
    Q.push_back(root); //push back the root element into the deque (outer deque)
    
    bool reverse = true; //Since we need to traverse in a zigzag way 

    while(!Q.empty())
    {
        vector<int> nums; //To insert elements into the matrix
        int n = Q.size(); //To keep track of Q size 
        deque<TreeNode*> dQ; // internal deque

        for(int i=0; i<n; i++)
        {   //Processing the Node: 
            TreeNode* curr = Q.front(); //Create a pointer and make it to point on front element of the Queue
            nums.push_back(curr->val);  //Push that element into the nums vector using that pointer 
            Q.pop_front();               //Pop out the element from the deque, (Meaning that we have processed it) 

            //Getting ready for another iteration
            if(reverse == true)
            {
                if(curr->left !=NULL) {dQ.push_front(curr->left);}
                if(curr->right !=NULL) {dQ.push_front(curr->right);}
            }
            else
            {
                if(curr->right !=NULL) {dQ.push_front(curr->right);}
                if(curr->left !=NULL) {dQ.push_front(curr->left);}
            }
        }
        
        Q.insert(Q.end(), dQ.begin(), dQ.end());
        result.push_back(nums);
        reverse = !reverse; //for zigzag 
    }
    return result; //Finally return the final matrix 
 }
};
