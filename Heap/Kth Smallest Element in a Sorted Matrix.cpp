//*********************************************** Using Max Heap *************************************************

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) 
    {
        priority_queue<int> Q; //Using max heap 
        
        for(int i=0; i<matrix.size(); i++)
        {
            for(int j=0; j<matrix[i].size(); j++)
            {
                Q.push(matrix[i][j]);   //Push Everything to max heap  
            }
        }
        
        int n = Q.size() - k; //Get the number of elements we have to pop out from the Queue 
        
        for(int i= 0; i<n; i++) //Traverse and pop out from the Queue 
        {
            Q.pop();
        }
        
        return Q.top(); //Finally return the Kth Smallest Element
    }
};
