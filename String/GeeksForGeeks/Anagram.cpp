//****************************************** Using Sorting *******************************************************
//Time: O(NlogN)
//Space: O(1)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    string str1 = "listen";
    string str2 = "silent";
    
    int n = str1.size();
    int m = str2.size(); 
    
    if(n != m)
    {
        cout<< "Not an Anagram";
        return 0;
    }
    
    sort(str1.begin(),str1.end());
    sort(str2.begin(),str2.end());
    
    for(int i=0; i<n; i++)
    {
        if(str1[i]!=str2[i])
        {
            cout << "Not an Anagram";
            return 0; 
        }
    }
    
    cout << "Is an Anagram";
    return 0;
}




//********************************************* Using Map **************************************************************
//Time: O(N)
//Space: O(N)

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
    string str1 = "listen";
    string str2 = "silent";
    
    int n = str1.size();
    int m = str2.size(); 
    
    if(n != m)
    {
        cout<< "Not an Anagram";
        return 0;
    }
    
    unordered_map<char,int> MyMap;
    
    for(int i=0; i<n; i++)
    {
        MyMap[str1[i]]++; 
    }
    
    for(int j=0; j<m; j++)
    {
        MyMap[str2[j]]++;
    }
    
    for(auto v: MyMap)
    {
        if(v.second != 2)
        {
            cout << "Not an Anagram";
            return 0;
        }
    }
    
    cout << "Is an Anagram";
    return 0;
}
