//************************************************************ SOLUTION 1: Without Using Extra Array ****************************************
//Time: O(N)
//Space: O(1) 

/* IDEA: We can make the result vector to hold the product values of left for each element in the array.
         And for other direction (right) we can use varialbe to calculate the product values of the right and then multiply it with the result vector. 
*/ 

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        int n = nums.size();
        
        vector<int> result(n); 
        
        result[0] = 1;  
 
        for(int i=1; i<n; i++)
            result[i] = result[i-1] * nums[i-1];
        
        int right = 1; 
        
        for(int i=n-1; i>=0; i--)
        {
            result[i] = result[i] * right;
            right = right * nums[i];
        } 
        return result; 
    }
};

//************************************************************* SOLUTION 2: Using Extra Array Solution ****************************************
//Time: O(N)
//Space: O(N)

/* IDEA: Traverse forward and calculate all the left products of each element in the array
         Traverse backward and calculate all the right products of each element in the array
         Finally, multiply both to get the final result vector. 
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        int n = nums.size();
        
        //Inititalize 3 arrays (result, left_product, right_product) 
        vector<int> result(n); 
        vector<int> left_products(n);
        vector<int> right_products(n);
        
        //
        left_products[0] = 1;    //Define the 1st element of left_product array 
        right_products[n-1] = 1; //Define the last element of right_product array 
        
        for(int i=1; i<n; i++)
            left_products[i] = left_products[i-1] * nums[i-1];
        
        for(int i=n-2; i>=0; i--)
            right_products[i] = right_products[i+1] * nums[i+1];
        
        for(int i=0; i<n; i++)
            result[i] = left_products[i] * right_products[i];
        
        return result; 
    }
};

//******************************************************************** SOLUTION 3: Using Division Method ****************************************
//Time: O(N)
//Space: O(1)

//NOTE: This method won't work if we have zero in the array. 

/* IDEA: Traverse the array and calculate the total product. 
         Traverse the array again and divide the current element with total product */

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> result(n); 
        int total_product = 1;
        
        for(int i=0; i<n; i++)
            total_product = total_product * nums[i];  
        
        for(int i=0; i<n; i++)
            result[i] = total_product/nums[i];
         
        return result; 
    }
};

