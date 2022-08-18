class Solution {
public:
    bool isValidPattern(string p) {
        if (p.size() == 0) return false;
        if (p.size() == 1) return true;
        for (int i = 1; i<p.size();i++){
            if (p[i] == '*' && p[i-1] == '*') return false;
        }
        return true;
    }
    bool isMatch(string s, string p) {
        int m=s.size(),n=p.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,false));
        dp[0][0]=true;
        for(int i=2;i<=n;i++){
            if(p[i-1]=='*')
            dp[0][i]=dp[0][i-2];
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(p[j-1]=='*'){
                     dp[i][j]=dp[i][j-2]||(dp[i-1][j]&&(s[i-1]==p[j-2]||p[j-2]=='.'));
                }
                else{
                     dp[i][j]=dp[i-1][j-1]&&(s[i-1]==p[j-1]||p[j-1]=='.');
                }
            }
        }
        return dp[m][n];
    }
};