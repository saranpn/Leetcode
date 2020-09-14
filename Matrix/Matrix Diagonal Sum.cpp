class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) 
    {
        int sum = 0;            //To calculate the sum 
        int n = mat.size();     //Row size 
        int m = mat[0].size();  //Column Size 
        
        // FOR ODD number of elements in Matrix (Since, the middle element will be added twice)
        int start = 0; 
        int end = n*m-1;
        
        int middle = start + (end-start)/2; //Find the middle element
        
        int row_matrix = middle/m; //Row index of the middle element 
        int col_matrix = middle%m; //Column index of the middle element
        int k = n-1; //To Add the row element if i!= j 
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(i==j) sum = sum + mat[i][j]; //if i==j
            }
            sum = sum + mat[i][k]; //To add the other element in the same row 
            k--;
        }
        
        if(n%2 == 1) sum = sum - mat[row_matrix][col_matrix]; //if ODD Matrix elements 
        return sum; //Finally Return the Sum 
    }
};
