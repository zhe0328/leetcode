class Solution {
public:
    string blank(int n){
        return string(n, ' ');
    }
    string join(vector<string> &words, int left, int right, string sep) {
        string s = words[left];
        for (int i = left + 1; i < right; ++i) {
            s += sep + words[i];
        }
        return s;
    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int n = words.size();
        int right = 0;
        while (true){
            int left = right;
            int num_word = 0;
            while (right < n && num_word + words[right].length() + right - left <= maxWidth) {
                num_word += words[right].length();
                right++; 
            }
            if (right == n) { // last line
                string s = join(words, left, n, " ");
                res.emplace_back(s + blank(maxWidth - s.length()));
                return res;
            }
            else if (right - left == 1){ // one word
                res.emplace_back(words[left]+blank(maxWidth - words[left].length()));
            }
            else {
                int num_space = maxWidth - num_word;
                int pre_space = num_space / (right - left - 1);
                int extra_space = num_space % (right - left - 1);
                string s_1 = join(words, left, left+extra_space+1, blank(pre_space+1));
                string s_2 = join(words, left+extra_space+1, right, blank(pre_space));
                res.emplace_back(s_1+blank(pre_space)+s_2);
            }
        }
    }
};