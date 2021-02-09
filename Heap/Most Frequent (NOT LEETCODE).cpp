#include <bits/stdc++.h> 
using namespace std; 
  
int mostFrequent(vector<int> &nums, int &n) 
{ 
    vector<int> result;
    
    map<int,int> MyMap;
    
    //Insert the number of occurences into the map 
    for(int i=0; i<n; i++)
    {
        MyMap[nums[i]]++;
    }
    

    int maxSoFar = INT_MIN;
    int ans = 0; 
    
    //Traverse the Map
    for(auto v: MyMap)
    {
        //Compare the Occurrences
        if(v.second > maxSoFar) //If greater then replace that with maxSoFar
        {
            maxSoFar = v.second;  //This is the Occurrences
            ans = v.first; //This is the number
        }
    }
    
    cout << ans;
    return ans; 
} 
  
// driver program 
int main() 
{ 
    vector<int> nums = { 1, 5, 2, 1, 3, 2, 1}; 
    int n = nums.size();
    mostFrequent(nums,n);
    return 0; 
} 
