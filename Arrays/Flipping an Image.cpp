//Source: https://leetcode.com/problems/flipping-an-image/
//Autho: Saravana Kumar

/* Given a binary matrix A, we want to flip the image horizontally, then invert it, and return the resulting image.

To flip an image horizontally means that each row of the image is reversed.  For example, flipping [1, 1, 0] horizontally results in [0, 1, 1].

To invert an image means that each 0 is replaced by 1, and each 1 is replaced by 0. For example, inverting [0, 1, 1] results in [1, 0, 0].

Example 1:

Input: [[1,1,0],[1,0,1],[0,0,0]]
Output: [[1,0,0],[0,1,0],[1,1,1]]
Explanation: First reverse each row: [[0,1,1],[1,0,1],[0,0,0]].
Then, invert the image: [[1,0,0],[0,1,0],[1,1,1]]
Example 2:

Input: [[1,1,0,0],[1,0,0,1],[0,1,1,1],[1,0,1,0]]
Output: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
Explanation: First reverse each row: [[0,0,1,1],[1,0,0,1],[1,1,1,0],[0,1,0,1]].
Then invert the image: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]

********************************************************************************************/

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
    for(int i=0; i<A.size(); i++)  //pointer i to go the particular row
    {
        int j = 0; //point j to point the first element in that row
        int k = A[i].size() - 1; //pointer k to point out the last elemement in that row
        
        //Flipping the array
        
            while(j<k) 
            {
                int temp = A[i][j]; //Store the first element of the first row in a variable called temp
                A[i][j++] = A[i][k]; //Assign last element as first element in that row. 
                A[i][k--] = temp; //Assign first element as last element in that row. 
                //increment j and decrement k for next iteration and do swapping until j < k 
            }
        
        //inverting the array
            
            for(j=0; j<A[i].size(); j++)  
            {
                if(A[i][j]==1)
                    A[i][j] = 0;
                else    
                    A[i][j] = 1;
            }
    }
        
    return A;
}
};
