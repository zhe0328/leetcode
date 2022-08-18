class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string,int> hash_map;
        int length = words[0].size();
        int total = words.size() * length;
        int num = words.size();
        vector<int> res;
        for (auto word : words){
            if (hash_map.find(word) == hash_map.end()){
                hash_map[word] = 1;
            }
            else {
                hash_map[word]++;
            }
        }
        for (int i = 0;i<s.size();i++){
            if (i+total<=s.size()) {
                unordered_map<string,int> temp_map;
                int temp_size = 0;
                for (int j = i; j<i+total; j+=length){
                    string cur = s.substr(j,length);
                    if (hash_map.find(cur) != hash_map.end()){
                        if (temp_map.find(cur) == hash_map.end()){
                            temp_map[cur] = 1;
                            temp_size++;
                        }
                        else if (hash_map[cur] > temp_map[cur]){
                            temp_map[cur]++;
                            temp_size++;
                        }
                    }
                    else {
                        break;
                    }
                }
                if (temp_size == num) {
                    res.push_back(i);
                }
            }
            else {
                break;
            }
        }
        return res;
    }
};