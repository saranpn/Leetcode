// Author: Saravana Kumar


class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
   
    //creating a priority queue of matrix to implement max-heap
    priority_queue<int,vector<int>> result;
    
 
    for(int i=0; i<matrix.size(); i++)
    {
        for(int j=0; j<matrix.size(); j++)
        {
            if(result.size()<k)
            { //Traversing through the nums vector and push it into the priority_queue
                result.push(matrix[i][j]);
            }
            //Afer Pushing, follow the same method 
            else if(matrix[i][j] < result.top())
            {
                result.pop();
                result.push(matrix[i][j]);
            }
        }
    }
    return result.top();
    }
};
