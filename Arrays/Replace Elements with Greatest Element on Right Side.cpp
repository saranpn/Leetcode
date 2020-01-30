// Source : https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/
// Author : Saravana Kumar



/* Given an array arr, replace every element in that array with the greatest element among the elements to its right, and replace the last element with -1.

After doing so, return the array.

 

Example 1:

Input: arr = [17,18,5,4,6,1]
Output: [18,6,6,6,1,-1]
 

Constraints:

1 <= arr.length <= 10^4
1 <= arr[i] <= 10^5


*********************************************************************************************************/

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        
        for(int i=0; i<arr.size(); i++){
            
            if(i == arr.size()-1)  // if i equals to the last element of the array
                arr[i] = -1;
            
            else
                arr[i] = *max_element(arr.begin()+i+1, arr.end());g
            
        }
            return arr;
    }
};
