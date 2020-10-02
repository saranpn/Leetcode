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
//Time Complexity: O(log(m*n)) (Because, let's say we have 12 elements, so we can cut 12 into 6, then 6 into 3 etc.)
//Space complexity: O(1) 

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        if(matrix.size() == NULL) return false; //Base case 
      
        //First Calculate total number of rows and columns in the matrix   
        int TotalRows = matrix.size();
        int TotalColumns = matrix[0].size();
        
        //Then make left pointer to point on first element and right pointer to point on last element of the matrix
        int left = 0; 
        int right = TotalRows * TotalColumns -1; 
        
        while(start <= end) 
        {
            //Then, Calculate middle element index considering it as 1D array 
            int middle = left + (right-left) /2; 
        
            //Then, Calculate middle element index considering it as 2D array 
            int middleElementValue = matrix[middle/column][middle%column]

            //if the element is found return true 
            if(target == middleElementValue) return true;
            
            //if the target is less than the middle element, then search only in the 1st half of the matrix 
            else if(target < middleElementValue) end = middle-1;
            
            //if the target is greater than the middle element, then search only in the 2nd half of the matrix 
            else if(target > middleElementValue) start = middle+1; 
        }
        return false; //if not found then, return false 
    }
};
