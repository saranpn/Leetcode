//*********************************************** Using Max Heap *************************************************

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) 
    {
        priority_queue<int> Q;
        
        int count = 0;
        
        for(int i=0; i<matrix.size(); i++)
        {
            for(int j=0; j<matrix[0].size(); j++)
            {
                if(count<k) 
                {
                    Q.push(matrix[i][j]);
                    count++;
                }
                
                else if(Q.top()>matrix[i][j])
                {
                    Q.pop();
                    Q.push(matrix[i][j]);
                }
            }
        }
        
        return Q.top();
    }
};
