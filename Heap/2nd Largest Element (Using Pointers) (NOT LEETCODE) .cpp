/* Find the Second Largest Element in the Array.
   Conditions: * The Array is NOT sorted 
               * The Array can have NEGATIVE values 
               * The Array can have DUPLICATE values 
               
********************************************************************************************************************************/
#include <iostream>
#include <vector> 
#include <limits.h> //header for INT_MIN
using namespace std;

int SecondLargest(vector<int> nums)
{
    int FirstMax = INT_MIN; //Initialize FirstMax
    int SecondMax = INT_MIN; //Initialize SecondMax
        
    int n = nums.size(); //Size of array 
    
    /* Here we are comparing first two elements of the 
       array, and storing the largest one in the "FirsMax"
       and the other one to "SecondMax" variable */ 
       
    if(nums[0]>nums[1]) {
        FirstMax = nums[0];
        SecondMax = nums[1];
    }
    else {
        FirstMax = nums[1];
        SecondMax = nums[0];
    }
    
    
    //Traverse the remaining elements of the array 
    for(int i=2; i<n; i++)
    {
        if(nums[i] > FirstMax) //if the current element is greater than the FirstMax 
        {
            SecondMax = FirstMax; //Then FirstMax is copied to SecondMax
            FirstMax = nums[i]; //And then the current element is copied to the FirstMax
        }
    
        //if current element is less than FirstMax, but greater than SecondMax, then simply replace the SecondMax with current element
        else if(nums[i] < FirstMax && nums[i] > SecondMax) SecondMax = nums[i];
        //if current element is less than the both FirstMax and SecondMax, then do nothing. 
        else if(nums[i] < FirstMax && nums[i] < SecondMax) continue;
        //if current element is equal to FirstMax or SecondMax, then do nothing. 
        else if(nums[i] == FirstMax || nums[i] == SecondMax) continue; 
    }
    
    cout << SecondMax;
    return SecondMax; //Finally return the SecondMax
}

int main()
{
    vector<int> nums = {3,6,-1,5,6,-4};
    
    SecondLargest(nums);
    
    return 0;
}
