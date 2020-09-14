//Reference: https://www.youtube.com/watch?v=-fS1pS1mxQc

class Solution {
public:
    int uniquePaths(int m, int n) 
    {
        //initializing the matrix with size mXn 
        vector<vector<int>> paths(m, vector<int>(n)); 
        
        //Fill all the bottom row with 1 
        for(int c=0; c<n; c++)
        {
            paths[m-1][c] = 1; 
        }
        
        //Fill all the last right column with 1 
        for(int r=0; r<m; r++)
        {
            paths[r][n-1] = 1; 
        }
        
        for(int r=m-2; r>=0; r--)
        {
            for(int c=n-2; c>=0; c--)
            {
                paths[r][c] = paths[r+1][c] + paths[r][c+1];
            }
        }
        
        return paths[0][0]; 
        
    }
};
