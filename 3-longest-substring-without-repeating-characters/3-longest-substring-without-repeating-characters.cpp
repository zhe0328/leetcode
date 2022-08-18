class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0; 
        int end = 0;
        int max_length = 1;
        int size = s.size();
        if (size == 0) return 0;
        unordered_map<char,int> hash_map;
        hash_map[s[start]] = 0;
        while (end <= size - 2) {
            if (hash_map.find(s[end+1]) == hash_map.end()){
                hash_map[s[end+1]] = end+1;
                end++;
            }
            else {
                int j = hash_map[s[end+1]];
                while (start != j+1){
                    hash_map.erase(s[start]);
                    start++;
                }
                hash_map[s[end+1]] = end+1;
                end++;
            }
            max_length=max(max_length,end-start+1);
        }
        return max_length;
    }
};