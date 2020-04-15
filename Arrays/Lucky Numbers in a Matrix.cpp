//Author: Saravana Kumar  
//Source: https://leetcode.com/problems/lucky-numbers-in-a-matrix/

/*
Given a m * n matrix of distinct numbers, return all lucky numbers in the matrix in any order.

A lucky number is an element of the matrix such that it is the minimum element in its row and maximum in its column.

 

Example 1:

Input: matrix = [[3,7,8],[9,11,13],[15,16,17]]
Output: [15]
Explanation: 15 is the only lucky number since it is the minimum in its row and the maximum in its column
*/

class Solution
{
public:
  vector < int >luckyNumbers (vector < vector < int >>&matrix)
  {
      
/* IDEA: 
            STEP 1: Traverse through the 1st row (by using matrix traversal method)
            STEP 2: After (1st)inner for loop (j) iteration ends we will be be having minimum row value of the 1st row and its index position (i.e. in which index it is there going from left to right)
            STEP 3: Before ending the j iteration, find the maximum value(using another for loop) in cloumn of that specified row index.
            
            STEP 4: By the end of first "i" teration we will be having minimum value of 1st row and the maximum value of that specified row index
            
            STEP 5: If the maximum and minimum matches each other, then it is the lucky number  
*/
         
    vector<int> ans;
    for(int i=0; i<matrix.size(); i++) //goes down at each iteration //for loop to work on columns
    {
        int minimum = 100005; //Minimum can't be this value in this problem
        int index = -1; // random, since index cannot be -1
        
        for(int j=0; j<matrix[i].size(); j++) //goes right at each iteration //for loop to work on rows
        {
            //Work 1: inside j iteration
            //Program to find the minimum number of the particular row
            if(matrix[i][j] < minimum)
            {
                minimum = matrix[i][j]; //minimum value of that row is found after work 1 inside j iteration and it is stored in a variable
                index = j; //Storing j value for index to find that particular index when going from left to right
            }
        }
        
        int maximum = -1; //Value which can't be maximum in this example
        
        //Program to find the maximum value of the particular column at j index (for loop to work on columns)
        for(int k=0; k < matrix.size(); k++)   //Go down from zero (column) for the specified index value.
        {
            if(matrix[k][index] > maximum)
            {
                maximum = matrix[k][index];  //Store the maximum element of that column
            }
        }  
            //Now we have minimum value of 1 row and maximum number of that specified row
        
        if(minimum == maximum) //Lucky number will the one with the found min and max are equal
        {
            ans.push_back(maximum); //Pushing that(minimum or maximum) value into the vector
        }
    }
    return ans;
  }
};

