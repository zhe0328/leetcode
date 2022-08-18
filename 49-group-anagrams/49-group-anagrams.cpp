class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> hash_map;
        for (auto str:strs){
            string key = str;
            sort(key.begin(), key.end());
            hash_map[key].push_back(str);
        }
        for (auto it = hash_map.begin(); it != hash_map.end(); ++it){
            res.push_back(it->second);
        }
        return res;
    }
};