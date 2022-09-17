class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        if (m == 1) return triangle[0][0];
        vector<vector<int>> dp(m, vector<int>(m));  
        dp[0][0] = triangle[0][0];      
        for (int i=1; i<m; i++){
            for (int j=0; j<i+1; j++){
                if (j == 0){
                    dp[i][j] = dp[i-1][j] + triangle[i][j];
                }
                else if (j == i){
                    dp[i][j] = dp[i-1][j-1] + triangle[i][j];
                }
                else {
                    dp[i][j] = min(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j];
                }
            }
        }
        int min_sum = INT_MAX;
        for (int j = 0; j < m; j++){
            min_sum = min(dp[m-1][j], min_sum);
        }
        return min_sum;
    }
};