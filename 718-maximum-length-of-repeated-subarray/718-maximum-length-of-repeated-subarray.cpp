class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        vector<vector<int>> dp(m, vector<int>(n));
        dp[0][0] = (nums1[0] == nums2[0]) ? 1 : 0;
        int res = dp[0][0];
        for (int i=0; i<m; i++){
            dp[i][0] = (nums1[i] == nums2[0]) ? 1 : 0;
            res = max(res, dp[i][0]);
        }
        for (int j=0; j<n; j++){
            dp[0][j] = (nums1[0] == nums2[j]) ? 1 : 0;
            res = max(res, dp[0][j]);
        }
        for (int i=1; i<m; i++){
            for (int j=1; j<n; j++){
                dp[i][j] = (nums1[i] == nums2[j]) ? dp[i-1][j-1]+1 : 0;
                res = max(res, dp[i][j]);
            }
        }
        return res;
    }
};