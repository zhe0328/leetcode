class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        vector<string> res(numRows);
        int j = 0;
        int flag = -1;
        string result;
        for (int i = 0; i< s.size(); i++){
            res[j] += s[i];
            if (j == 0 || j == numRows - 1){
                flag = -flag;
            }
            j += flag;
        }
        for (int k = 0; k<numRows;k++){
            result+=res[k];
        }
        return result;
    }
};