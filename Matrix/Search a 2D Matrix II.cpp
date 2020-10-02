// Link: https://www.youtube.com/watch?v=Ohke9-qwAKU

/* Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
Example:

Consider the following matrix:

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]

********************************************************************************************************************************************
IDEA:  If the Matrix is sorted in this type, then we cannot do binary search by considering it as 1D array. We need some other approach 

 Approach 1: Start from the [1st_row][last_column] and start eliminating,
               rows from bottom to up and columns from left to right
                
   Approach 2: Start from the [last_row][1st_column] and start eliminating, 
               rows from top to bottom and columns from right to left  
*********************************************************************************************************************************************
//Time: O(m + n) 
(What is the farthest I can go from Bottom to Up?? Depends on number of rows m)
(What is the farthest I can go from left to right?? Depends on number of columns n)  */

//Space: O(1) 


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
{
    if(matrix.size() == 0) return false; //Base Case 

    //Approach 1:
    int row = 0; //1st row (ROW INDEX)
    int col = matrix[0].size()-1; //last column (COLUMN INDEX)

    //Be in the loop, until the row is smaller than given row size and column is greater than zero
    while(row < matrix.size() && col >= 0)
    {
        int element = matrix[row][col]; // Element in the 2D Array

        if(target == element) return true; //if Target is found, return True

        else if(target > element) row++; //if Target is greater than the element, then eliminate rows from Bottom to up

        else if(target < element) col--; //if Target is lesser than the element, then eliminate cols from left to right 
    }

    return false; //Return false if the element is not found 
}
};

//***************************************************************** FULL CODE ****************************************************************
#include <iostream>
#include <vector> 
using namespace std;

int main()
{
    vector<vector<int>> matrix = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22}};
    int target = 12; 

    if(matrix.size() == 0)
    {
        cout << "Matrix is empty";
        return false;
    }
    
    int row = 0; //1st row
    int col = matrix[0].size()-1; /last column 
    
    while(row < matrix.size() && col>=0) //be in the loop, until the row is smaller than given row size and column is greater than zero
    {
        if(target == matrix[row][col])
        {
            cout << "Found";
            return true;
        }

        else if(target > matrix[row][col])
        {
            row++; //Elimiate that row by row++, because row starts from 0
        }
        else if(target < matrix[row][col])
        {
            col--; //Elimiate that col by col--, because col starts from last
        }
    }
    
    cout << "Not found"; 
    return false;

    return 0;
}
