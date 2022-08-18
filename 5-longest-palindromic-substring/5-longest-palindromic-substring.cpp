class Solution {
public:
    string longestPalindrome(string s) {
        int size = s.size();
        if (size < 2) {
            return s;
        }
        vector<vector<int>> dp(size, vector<int>(size));
        int start = 0;
        int max_len = 1;
        for (int i = 0; i < size; i++) {
            dp[i][i] = true;

        }
        for (int L = 2; L <= size; L++) {
            for (int i = 0; i < size; i++) {
                int j = L + i - 1;
                if (j >= size) {
                    break;
                }
                if (s[i] != s[j]) {
                    dp[i][j] = false;
                } else {
                    if (j - i < 3) {
                        dp[i][j] = true;
                    } else {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }
                if (dp[i][j] && j - i + 1 > max_len) {
                    max_len = j - i + 1;
                    start = i;
                }
            }
        }
        return s.substr(start, max_len);
    }
};