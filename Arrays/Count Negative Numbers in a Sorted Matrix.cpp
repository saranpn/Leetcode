//Source: https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/
// Author : Saravana Kumar

/***************************************************************************************************** 

Given a m * n matrix grid which is sorted in non-increasing order both row-wise and column-wise. 

Return the number of negative numbers in grid.

 

Example:

Input: grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
Output: 8
Explanation: There are 8 negatives number in the matrix.

******************************************************************************************************/

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        
    int k = 0;
        
    for(int i=0; i<grid.size(); i++)
    {    
        
        for(int j=0; j<grid[i].size(); j++)
         {
             if (grid[i][j] < 0)
                k++ ;
         }
    }
    
    return k;
        
    }
};
