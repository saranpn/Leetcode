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

IDEA: --> Since the matrix is sorted on both rows and column, we are following a different approach here. 
      --> Start from the 1st row, last column element and check if that is the target value,
      --> if YES, return true (Target found)
      --> if NOT, do things, if the target value is greater than that element, then eliminate that row 
                         if the target value is less than that element, then eliminate that col

**********************************************************************************************************************************************/

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
