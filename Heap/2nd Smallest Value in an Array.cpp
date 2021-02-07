#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

int SecondSmallest(vector<int> nums)
{
  int n = nums.size();

  int first_min = nums[1];
  int second_min = nums[0];

  for(int i=0; i<n; i++)
  {
    if(nums[i] < first_min)
    {
      second_min = first_min;
      first_min = nums[i];
    }
    
    else if(nums[i] < second_min)
    {
      second_min = nums[i];
    }
  }
  
  cout << second_min; 
  return second_min;
}

int main() 

{
  vector<int> nums = {6,5,2,1,7,3};
  
  SecondSmallest(nums);
  
  return 0;
}
