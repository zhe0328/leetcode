class Solution {
    
public:
    unordered_map<int,vector<char>> hash_map = {
        {2, {'a','b','c'}},
        {3, {'d','e','f'}},
        {4, {'g','h','i'}},
        {5, {'j','k','l'}},
        {6, {'m','n','o'}},
        {7, {'p','q','r','s'}},
        {8, {'t','u','v'}},
        {9, {'w','x','y','z'}}
    };
    vector<string> backtrack(vector<string> before, int num){
        vector<char> hash_value = hash_map[num];
        vector<string> after;
        if (!before.size()) {
            for (auto value : hash_value){
                string temp;
                temp = value;
                after.push_back(temp);
            }
            return after;
        }
        for (int i=0; i<before.size(); i++){
            for (auto value : hash_value){
                string temp = before[i] + value;
                after.push_back(temp);
            } 
        }
        return after;
    }
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        for (auto digit : digits) {
            int num = digit-'0';
            res = backtrack(res, num);
        }
        return res;
    }
};