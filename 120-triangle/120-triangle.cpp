class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        if (m == 1) return triangle[0][0];
        vector<vector<int>> dp(2, vector<int>(m));  
        dp[0][0] = triangle[0][0];      
        for (int i=1; i<m; i++){
            int cur = i % 2;
            int prev = 1 - cur;
            for (int j=0; j<i+1; j++){
                if (j == 0){
                    dp[cur][j] = dp[prev][j] + triangle[i][j];
                }
                else if (j == i){
                    dp[cur][j] = dp[prev][j-1] + triangle[i][j];
                }
                else {
                    dp[cur][j] = min(dp[prev][j-1], dp[prev][j]) + triangle[i][j];
                }
            }
        }
        return *min_element(dp[(m - 1) % 2].begin(), dp[(m - 1) % 2].end());
    }
};