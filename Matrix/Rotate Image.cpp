/* Example 1:

Given input matrix = 
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],

rotate the input matrix in-place such that it becomes:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]

*****************************************************************************************/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
  
        reverse(matrix.begin(), matrix.end());  
        
        /*  After Revesing the matrix: 
        
                    7 8 9
                    4 5 6
                    1 2 3               */
        
        for(int i=0; i<matrix.size(); i++) 
        {   
            for(int j=i+1; j<matrix[i].size(); j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        /*  After swapping: 

                    7 4 1
                    8 5 2
                    8 6 3               */
    }
};
