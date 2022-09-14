class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> hash_map;
        for (auto c:text) {
            if (hash_map.find(c) == hash_map.end()){
                hash_map[c] = 1;
            }
            else {
                hash_map[c]++;
            }
        }
        string word1 = "ban";
        string word2 = "lo";
        int res = INT_MAX;
        for (auto c:word1){
            res = min(res, hash_map[c]);
        }
        for (auto c:word2){
            res = min(res, hash_map[c]/2);
        }
        return res;
    }
};