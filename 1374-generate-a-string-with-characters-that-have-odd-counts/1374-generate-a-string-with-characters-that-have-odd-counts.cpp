class Solution {
public:
    string generateTheString(int n) {
        string res;
        for (int i=0; i<n; i++){
            res += 'a';
        }
        if (!(n%2)) { // n is even
            res[0] = 'b';
        }
        return res;
    }
};