class Solution {
public:
    string countAndSay(int n) {
        if (n==1) return "1";
        string cur = "1";
        while (n > 1) {
            string temp;
            int pos = 0;
            int start = 0;
            while (pos < cur.size()) {
                while (pos < cur.size() && cur[pos] == cur[start]) {
                    pos++;
                }
                temp += to_string(pos - start) + cur[start];
                start = pos;
            }
            cur = temp;
            n--;
        }
        return cur;
    }
};