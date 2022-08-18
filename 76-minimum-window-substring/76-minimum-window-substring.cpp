class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<int,int> hash_t;
        for (int i=0;i<t.size();i++){
            if (hash_t.find(t[i]) == hash_t.end()){
                hash_t[t[i]] = 1;
            }
            else {
                hash_t[t[i]]++;
            }
        }
        int count = 0, left = 0, right = 0, min_left = 0, min_right = s.size();
        while (right < s.size()){
            if (hash_t.find(s[right]) != hash_t.end() && --hash_t[s[right]]>=0){
                count++;
            }
            while (count == t.size()){
                if (right-left<min_right-min_left){
                    min_left = left;
                    min_right = right;
                }
                if (hash_t.find(s[left]) != hash_t.end() && ++hash_t[s[left]]>0){
                    count--;
                }
                left++;
            }
            right++;
        }
        return min_right-min_left+1 > s.size() ? "": s.substr(min_left, min_right-min_left+1);
    }
};