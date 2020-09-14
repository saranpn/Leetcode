/*  LINK: https://www.youtube.com/watch?v=eT0UqrYuqbg&t=133s

/* IDEA: // *************************************** Only applicable for "SORTED MATRIX" **************************************************

--> Since, the Matrix is sorted. Divide the matrix into 2 halves. 
           And traverse through only 1 half to find the target. 
 
--> Step 1: Find the middle element of the matrix, by keeping a pointer at 1st and last element of the matrix. 
--> Step 2: Find if the target is less or greater than the middle element.
            If less, move the last pointer to the middle, and search only in the 1st half. 
            If more, move the start pointer to the middle, and search only in the 2nd half. 
--> Step 3: Continue this untill, we find the target (OR) the start pointer equals to end.

**************************************************************************************************************************************************/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        if(matrix.size() == NULL) return false; //Base case 
      
        int row = matrix.size(); //will give you the row size 
        int column = matrix[0].size(); //will give you the column size 
        
        int start = 0; //matrix element count starts from 0 
        int end = row * column -1;  //last number count of the matrix 
        
        while(start <= end) 
        {
            //will give you the middle index of the ARRAY at 1st iteration 
            int middle = start + (end-start) /2; 
        
            int row_matrix = middle/column; //Will give the ROW index of the middle element for MATRIX @ 1st iteration
            int col_matrix = middle%column; //Will give the COLUMN index of the middle element for MATRIX @ 1st iteration

            //if the element is found return true 
            if(target == matrix[row_matrix][col_matrix]) 
                return true;
            
            //if the target is less than the middle element, then search only in the 1st half of the matrix 
            else if(target < matrix[row_matrix][col_matrix]) 
                end = middle-1;
            
            //if the target is greater than the middle element, then search only in the 2nd half of the matrix 
            else if(target > matrix[row_matrix][col_matrix]) 
                start = middle+1; 
        }
        return false; //if not found then, return false 
    }
};
