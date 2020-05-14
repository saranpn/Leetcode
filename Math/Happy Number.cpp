//Source: https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/528/week-1/3284/
//Author: Saravana Kumar 

/*  Write an algorithm to determine if a number n is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum
of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), 
or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Return True if n is a happy number, and False if not.

Example: 

Input: 19
Output: true
Explanation: 
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1

*************************************************************************************************************/

class Solution {
public:
    bool isHappy(int n) {
        
    unordered_set<int> MySet;
    
    while(n != 1) //Which will contiue to loop untill it finds 1 (Ans) or infinte loop is found
    {
        if(MySet.count(n)) return false; //Check if n is in the set and return false ---> means infinite loop
        MySet.insert(n); //if it is not in the set, then insert it into MySet

        int next = 0; //To store the next value after squaring each integer
    
        //first loop n will be 29
        //second loop n will be 2
        while(n > 0) 
        {
            //Find 2nd digit 
            //(first loop = 9, second loop = 2)
            int second_digit = n % 10;  

            //Squre the second digit add it with first digit and store it in first digit
            //(first loop = 0 + 9*9 = 81, second loop = 81 + 2*2 = 85)
            //After 2nd loop the new element will be in the next
            next = next + (second_digit*second_digit);
        
            //Find 1st digit and store it in n
            //(first loop = 2, second loop = 0, then inner while loop will end)
            n = n/10;
        }
        
        n = next; //Store the next value in we got.
    }
    
    return true; //When n=1, outer while is exited and return true 
    
    }
};
