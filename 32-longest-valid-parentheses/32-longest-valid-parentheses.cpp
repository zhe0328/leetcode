class Solution {
public:
    int longestValidParentheses(string s) {
        int size = s.size(), res = 0;
        vector<int> dp(size,0);
        for (int i = 1; i < size; i++){
            if (s[i] == ')' && s[i-1] == '(') {
                dp[i] = (i >= 2) ? dp[i-2] + 2 : 2;
            }
            else if (s[i] == ')' && s[i-1] == ')'){
                int before = i-dp[i-1]-1;
                if (before >= 0 && s[before] == '(') {
                    dp[i] = (i-dp[i-1]-2 > 0) ? dp[i-1] + dp[i-dp[i-1]-2] + 2 : dp[i-1]+2;
                }
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};