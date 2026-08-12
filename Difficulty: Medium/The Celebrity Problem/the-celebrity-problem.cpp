class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();
        
        int top = 0;
        int down = n - 1;
        
        // Eliminate people who cannot be the celebrity
        while(top < down){
            
            // top knows down
            // Therefore, top cannot be the celebrity
            if(mat[top][down] == 1)
                top++;
            
            // down knows top
            // Therefore, down cannot be the celebrity
            else if(mat[down][top] == 1)
                down--;
            
            // Neither knows the other
            // Therefore, neither can be the celebrity
            else{
                top++;
                down--;
            }
        }
        
        // Only one possible candidate should remain
        if(top > down) return -1;
        
        // Verify that the candidate actually satisfies
        // both celebrity conditions
        for(int i = 0; i < n; i++){
            
            if(top == i) continue;
            
            // Candidate must NOT know anyone
            // AND everyone must know candidate
            if(mat[top][i] == 0 && mat[i][top] == 1)
                continue;
            else
                return -1;
        }
        
        return top;
    }
};