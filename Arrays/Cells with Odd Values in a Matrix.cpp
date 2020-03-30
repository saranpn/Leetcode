//Source: https://leetcode.com/problems/cells-with-odd-values-in-a-matrix/
//Author: Saravana Kumar


/*********************************************************************************************************
Given n and m which are the dimensions of a matrix initialized by zeros and given an array indices where indices[i] = [ri, ci]. 
For each pair of [ri, ci] you have to increment all cells in row ri and column ci by 1.

Return the number of cells with odd values in the matrix after applying the increment to all indices.

Example 1:
Input: n = 2, m = 3, indices = [[0,1],[1,1]]
Output: 6
Explanation: Initial matrix = [[0,0,0],[0,0,0]].
After applying first increment it becomes [[1,2,1],[0,1,0]].
The final matrix will be [[1,3,1],[1,3,1]] which contains 6 odd numbers.

************************************************************************************************************/

class Solution {
public:
   int oddCells(int n, int m, vector<vector<int>>& indices) {
      vector<int> row_inc(n); // increment values for rows
      vector<int> col_inc(m); // increment values for columns
      
      for (const auto& index : indices)
        {
         row_inc [index[0]]++; 
         col_inc[index[1]]++;
        }      
      int cnt = 0;
      for (int r = 0; r < n; r++)
        for (int c = 0; c < m; c++)
          cnt += (row_inc[r] + col_inc[c])%2;
      
      return cnt;
    }
};
