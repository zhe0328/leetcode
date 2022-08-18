class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if (n==0) return 0;
        int begin = s[0] - '0';
        if (!begin) return 0;
        if (n==1 && begin > 0) return 1;
        if (n==1) return 0;
        int dp[n];
        dp[0] = 1;
        dp[1] = 1;
        if ((begin == 1 && (s[1]-'0')>0) || (begin == 2 && (s[1]-'0') <= 6 && (s[1]-'0')>0)){
            dp[1] = 2;
        }
        else if ((s[1]-'0') == 0 && begin>2){
            dp[1] = 0;
            return 0;
        }
        for (int i=2; i<n;i++){
            int cur = s[i] - '0';
            int prev = s[i-1] - '0';
            if (cur == 0){
                if (prev == 1 || prev == 2){
                    dp[i] = dp[i-2];
                }
                else {
                    dp[i] = 0;
                    return 0;
                }
            }
            else {
                if (prev == 1 || (prev == 2 && cur <= 6)){
                    dp[i] = dp[i-2] + dp[i-1];
                }
                else {
                    dp[i] = dp[i-1];
                }
            }
        }
        return dp[n-1];
    }
};