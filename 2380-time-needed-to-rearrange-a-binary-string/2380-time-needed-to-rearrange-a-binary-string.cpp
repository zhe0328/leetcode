class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int zeros = 0;
        int res = 0;
        for (int i=0; i<s.size();i++){
            if (s[i] == '0') {
                ++zeros;
            }
            if (s[i] == '1' && zeros){
                res = max(res+1, zeros);
            }
        }
        return res;
    }
};