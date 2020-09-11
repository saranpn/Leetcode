//************************************************** Solution 1: Using Pointers ********************************************************************************
 
// Time: O(n)  
// Space: O(1)

class Solution {
public:
    void reverseString(vector<char>& s) {
        
        int i=0, j=s.size()-1;
        
        for(i,j; i<j; ++i, --j)
            swap(s[i],s[j]);
    }
};

//************************************************** Solution 2: Using STL ********************************************************************************
 
// Time: O(n)  
// Space: O(1)

class Solution{
public:
    void reverseString(vector<char>& s) {
        
       reverse(s.begin(),s.end());
    }
};

//************************************************** Solution 3: Using Stack (not for Leetcode) ***********************************************************************
 
// Time: O(n)  
// Space: O(N)

#include <iostream>
#include <vector> 
#include <stack>
using namespace std;

int main()
{
    vector<char> s = {'s','a','r','a','n'};
    vector<char> result; 
    stack<char> MyStack;
    int n = s.size();
    for(int i=0; i<n; i++)
    {
        MyStack.push(s[i]);
    }
    
    while(!MyStack.empty())
    {
        result.push_back(MyStack.top());
        MyStack.pop();
    }
    
    int m = result.size();
    
    for(int j=0; j<m; j++)
    {
        cout << result[j] << " ";
    }

    return 0;
}
