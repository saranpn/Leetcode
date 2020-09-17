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

//************************************************************************* FULL CODE ******************************************************************************
#include <iostream>
#include <vector> 
#include <algorithm>

using namespace std;

int uniquePaths(vector<vector<int>> matrix)
{
    int row = matrix.size();
    cout << "m = " << row << endl;
    int col = matrix[0].size();
    cout << "n = " << col << endl;
    
    for(int i=0; i<col; i++) 
    {
        matrix[row-1][i] = 1; //fix row-1 and increment column from 0 to last column
    }
    
    for(int i=0; i<row; i++)
    {
        matrix[i][col-1] = 1; //fix col-1 and increment column from 0 to last row
    }
    
    for(int i=row-2; i>=0; i--) //start from row-2 and decrement till 0
    {
        for(int j=col-2; j>=0; j--) //start from col-2 and decrement till 0
        {
            //Add the two possible path that can be taken from the [i][j] index,
            //We can go down, which is [i+1][j]
            //We can go right, which is [i][j+1]
            matrix[i][j] = matrix[i+1][j] + matrix[i][j+1]; 
        }
    }
    
    cout << matrix[0][0];
}

int main()
{
    //vector<vector<int>> matrix = {{0,0,0,0,0,0,0},{0,0,0,0,0,0,0},{0,0,0,0,0,0,0}};
    vector<vector<int>> matrix(7,vector<int>(3));
    uniquePaths(matrix);
    
    return 0;
}
