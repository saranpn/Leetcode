/****************************** IDEA: *************************************************************** 
    Step 1: Traverse through the Sparse Matrix and keep a count of # of Non-Zero Elements 
    Step 2: Create a Compact Matrix of row size 3 and column size of # of Non-Zero Elements
    Step 3: Traverse through the Sparse Matrix, and whenever you find non-zero element
            you have to do 3 things in compact matrix and increment k. 
            
            They are, compactMatrix[0][k] = i; //Store the row number 
                      compactMatrix[1][k] = j; //Store the column number 
                      compactMatrix[2][k] = sparseMatrix[i][j]; //Store the value 
                      And increment k
********************************************************************************************************/
//FULL CODE: 

#include <iostream> 
using namespace std;

int main() 
{ 
	// Assume 4x5 sparse matrix 
	int sparseMatrix[4][5] = 
	{ 
		{0 , 0 , 3 , 0 , 4 }, 
		{0 , 0 , 5 , 7 , 0 }, 
		{0 , 0 , 0 , 0 , 0 }, 
		{0 , 2 , 6 , 0 , 0 } 
	}; 

	int nonZero_Elements  = 0; 
	
	for (int i = 0; i < 4; i++) 
	{
		for (int j = 0; j < 5; j++)
		{
    	    if (sparseMatrix[i][j] != 0) 
		    nonZero_Elements ++; 
		} 
	}

	//Row value of Sparse Matrix will always be 3 
	//Column Value of the Sparse Matrix will always be # of Non-Zero elements in the Original Matrix  
	//Create a new compactMatrix
	int compactMatrix[3][nonZero_Elements]; 

	int k = 0; //Take k value 0, used for compactMatrix operation 
	
	for (int i = 0; i < 4; i++) 
	{
        for (int j = 0; j < 5; j++) 
        {
            if (sparseMatrix[i][j] != 0) 
            { 
                compactMatrix[0][k] = i;   //Store the row number in compactMatrix
                compactMatrix[1][k] = j;   //Store the column number in compactMatrix 
                compactMatrix[2][k] = sparseMatrix[i][j]; ////Store the value in compactMatrix
                k++;  //increment k value
            } 
        }
	}

    //Print out the compactMatrix 
	for (int i=0; i<3; i++) 
	{ 
		for (int j=0; j<nonZero_Elements ; j++) 
		{
		    cout << compactMatrix[i][j] << " ";
		}
		cout << endl;  
	} 
	
	return 0; 
} 
