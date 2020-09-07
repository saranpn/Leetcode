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
