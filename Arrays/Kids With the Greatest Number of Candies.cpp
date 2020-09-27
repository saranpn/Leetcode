class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) 
    {
        int n = candies.size();
        vector<bool> result(n); 
        
        int maximum = 0;
        maximum = *max_element(candies.begin(),candies.end());
        cout << maximum << endl; 
        
        for(int i=0; i<n; i++)
        {
            if(candies[i]+extraCandies >= maximum)
            {
                result[i] = true;
            }
            
            else if(candies[i]+extraCandies < maximum)
            {
                result[i] = false;
            }
        }
        
        return result; 
    }
};
