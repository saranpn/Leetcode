//Time: O(N+M) 
//Space: O(1)

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) 
    {
        if(grid.size()==0) return {};
        
        //Start by Top Right Corner
        int row = 0; //WKT, At Top, Row would be Zero
        int col = grid[0].size()-1; //WKT, At Right Corner, Column would be Matrix.size(which gives the row size) - 1
        
        int Row_Size = grid.size(); //Get Row-Size of the Matrix  
    
        int count = 0; //To count the negative numbers
        
        while(row < grid.size() && col >=0) 
        {
            if(grid[row][col] <= -1)  //If it is a negative number, then
            {
                count = count + (Row_Size-row); //We know all the bottom elements in the column would also be the negative numbers, so add all that elements to the count 
                col--; //Then, eliminate that column by decrementing col variable
            }
            else
            {
                row++; //If positive number, then all the element to the left would also be +ve numbers, so eliminate that row 
            }
        }
        return count; //Finally return count 
    }
};
