// Source : https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/
// Author : Saravana Kumar

/* Given an integer n, return any array containing n unique integers such that they add up to 0.

Example 1:

Input: n = 5
Output: [-7,-1,1,3,4]
Explanation: These arrays also are accepted [-5,-1,1,2,3] , [-3,-1,2,-2,4].
Example 2:

Input: n = 3
Output: [-1,0,1]
Example 3:

Input: n = 1
Output: [0]

***************************************************************************************************************/

class Solution {
public:
    vector<int> sumZero(int n) {
        
        vector<int> res;                //Create a vector to store the elements
        
        if(n%2!=0)                      //If the array size is odd,
            res.push_back(0);           //then add one zero to the array.
        
        for(int i=1; i<=n/2; i++) 
        {                                //If the array size is even,
            res.push_back(i);            //then add a positive number starting from i
            res.push_back(-i);           // and a negative number i                        
        }                                // so that it sums up to zero
        
        return res;                      //Return the final vector
    }
};

/*Explanation:

Example 1: 
if n = 1 -------------------> then if loop is executed by adding 0 to the vector
Then it comes to for loop and checks the condition. since 1 is not less than or equal to 0.5 for loop won't execute.
Then finally the vector is returned.

Example 2:
if n = 2 ------------------> then if loop won't execute. Since its remainder will become zero.
Then it comes to for loop. Since 1(i) <= 2/2, for loop executes one time and adds 1 and -1 to the array.
for loop condition ---> (i < n/2) also works.

Example 3: 
if n = 3 -------------------> both if loop and for loop executes one time.
for loop condition ---> (i < n/2) also works.

Example 4: 
if n = 4 --------------------> for loop will be executed twice to add 4 values.
for loop condition ---> (i < n/2) wont work.
This is the reason we are using (i <= n/2) this condition in for loop. 




