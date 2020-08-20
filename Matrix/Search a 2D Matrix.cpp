/*  LINK: https://www.youtube.com/watch?v=eT0UqrYuqbg&t=133s

QUESTION: 

Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
Example 1:

Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 3
Output: true

****************************************************************************************************************************************/

/* IDEA: // *************************************** Only applicable for "SORTED MATRIX" **************************************************

//Consider the matrix as an array and do the following: 
--> Take two pointer "row" and "column"
--> With that caluclate the "left" pointer and "right" pointer of the array
After this, will come inside the while loop. 
--> Then, with the help of left and right pointer, calculate the middle pointer of the array. 

//Consider the matrix as Matrix iteslf and do the folowing: 
--> with the help of "middle" pointer and "column" calculate the "row_matrix" value of the matrix.
--> with the help of "middle" pointer and "column" calculate the "col_matrix" value of the matrix.

//Then,
--> if the target == matrix[row_matrix][col_matrix], then return true (element found)
--> if the target < matrix[row_matrix][col_matrix], then cut the matrix into half by reducing the right pointer position
-->  if the target > matrix[row_matrix][col_matrix], then cut the matrix into half by increasing the left pointer position 

**************************************************************************************************************************************************/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
    if(matrix.size() == 0) { return false;}
        
    int row = matrix.size();
    int column = matrix[0].size();
    
    int left = 0;
    int right = row * column -1; 
    
    
    while(left<=right)
    {
        int middle = left + (right-left)/2; //will give you the middle index of the ARRAY
        
        int row_matrix = middle/column; //[middle/column] --> Will give the ROW index of the middle element for MATRIX
        int col_matrix = middle%column; //[middle%column] --> Will give the COLUMN index of the middle element for MATRIX 
        
        if(target == matrix[row_matrix][col_matrix])
        {
            return true;
        }
        else if(target < matrix[row_matrix][col_matrix])
        {
            right = middle - 1;
        }
        else if(target > matrix[row_matrix][col_matrix])
        {
            left = middle + 1;
        }
    }

    return false;
    }
};
