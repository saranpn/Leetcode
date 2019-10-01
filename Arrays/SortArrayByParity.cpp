//Author: Saravana Kumar
//

/*Given an array A of non-negative integers, return an array consisting of all the even elements of A, followed
by all the odd elements of A. You may return any answer array that satisfies this condition.

Example 1:
Input: [3,1,2,4]
Output: [2,4,3,1]
The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.

Note:
1 <= A.length <= 5000
0 <= A[i] <= 5000
*/
************************************************************************************************************
//Solution 1:

class Solution {
public:
    
    /*Creating a boolean function called isEven which takes int x as parameter and 
    return 0 if the element x is Even */ 
    
    bool isEven(int &x)
    {
        return x % 2 == 0;
        
    }    
    
    vector<int> sortArrayByParity(vector<int> &A) {
    
        /* two pointer, one from left to right, another from right to left
        if left is odd number and right is even number, switch them */
        
        int l = 0; //left pointer
        int r = A.size() -1; //right pointer
        
        while(l<r) {
            
            if( !isEven(A[l]) && isEven(A[r]) ) 
                swap (A[l],A[r]);
            
            if( isEven(A[l]) ) 
                l++;
            
            if( !isEven(A[r]) )
                r--;
            }
        return A;
    }
};

*******************************************************************************************
//Solution 2:

class Solution {
public:

/* Two pointer i and j which points on odd and even and swap the elements when found */
    vector<int> sortArrayByParity(vector<int>& A) {
        int i=0;
        for (int j = 0; j < A.size(); ++j) {
            if (A[j] % 2 == 0) {
                swap(A[i], A[j]);
                i++;
            }
        }
        return A;
    }
};

*********************************************************************************************

