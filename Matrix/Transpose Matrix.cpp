class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {  
        int n = A.size(); 
        int m = A[0].size();
        
        vector<vector<int>> answer(m ,vector<int>(n)); 
        
         for(int i = 0; i < m; i++) 
         { 
            for(int j = 0; j < n; j++) 
            { 
                answer[i][j] = A[j][i];
            }
        } 
        
        return answer;
    }
};
