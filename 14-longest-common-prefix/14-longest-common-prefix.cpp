class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix;
        int size = strs.size();
        int min_length = strs[0].size();
        for (int i = 0; i < size; i++) {
            min_length = min_length < strs[i].size() ? min_length : strs[i].size();
        }
        int j = 0;
        while (j < min_length) {
            char temp = strs[0][j];
            bool flag = true;
            for (int i = 0; i < size; i++) {
                if (temp != strs[i][j]) {
                    flag = false;
                    break;
                }
            }
            if (flag == false) {
                break;
            }
            else {
                prefix += temp;
                j++;
            }
        }
        return prefix;
    }
};