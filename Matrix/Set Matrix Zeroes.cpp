/* QUESTION: 
Given an m x n matrix. If an element is 0, set its entire row and column to 0.

Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]  */ 


/* SOLUTION 1: BRUTE FORCE METHOD   (NOT OPTIMAL)

Step 1: Create a two separate vector, 1 vector with row size of the matrix and other vector with column size of the matrix. 
Step 2: Traverse through the matrix, and if you find a zero element, then make the corresponding row vector and column vector to be true. 
                        Example: row_zero = [0 1 0];
                             column_zero = [0 1 0];
Step 3: Then traverse through the matrix again, and if find row_zero vector to be true or col_zero vector to be true, then replace that 
element in the matrix to be zero. 

                      
//TIME COMPLEXITY: 
//SPACE COMPLEXITY: O(M + N)       */


class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
    int h = matrix.size();
    int w = matrix[0].size();
    
    vector<bool> row_zero(h);
    vector<bool> column_zero(w);
    
    for(int i=0; i<h; i++)
    {
        for(int j=0; j<w; j++)
        {
            if(matrix[i][j] == 0)
            {
                row_zero[i] = true;
                column_zero[j] = true;
            }
        }
    }
        
    for(int i=0; i<h; i++)
    {
        for(int j=0; j<w; j++)
        {
           if(row_zero[i] == true || column_zero[j] ==true)
           {
               matrix[i][j] = 0;
           }
        }
    }
    
    for(int i=0; i<h; i++)
    {
        for(int j=0; j<w; j++)
        {
           if(column_zero[j] ==true)
           {
               matrix[i][j] = 0;
           }
        }
    }
    }
};


// ************************************************************ FULL CODE: *************************************************************** 
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
    int h = matrix.size();
    int w = matrix[0].size();
    
    vector<bool> row_zero(h);
    vector<bool> column_zero(w);
    
    for(int i=0; i<h; i++)
    {
        for(int j=0; j<w; j++)
        {
            if(matrix[i][j] == 0)
            {
                row_zero[i] = true;
                column_zero[j] = true;
            }
        }
    }
        
    for(int i=0; i<h; i++)
    {
        for(int j=0; j<w; j++)
        {
           if(row_zero[i] == true || column_zero[j] ==true)
           {
               matrix[i][j] = 0;
           }
        }
    }
    
    for(int i=0; i<h; i++)
    {
        for(int j=0; j<w; j++)
        {
           if(column_zero[j] ==true)
           {
               matrix[i][j] = 0;
           }
        }
    }
        
    }
};
