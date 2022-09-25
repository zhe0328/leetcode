class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> res(length, 0);
        unordered_map<int,int> hashMap; // hashMap[idx] = added num
        int m = updates.size();
        for (int i=0; i<m; i++){
            int startIdx = updates[i][0];
            int endIdx = updates[i][1];
            int inc = updates[i][2];
            res[startIdx] += inc;
            if (endIdx+1<length){
                res[endIdx+1] -= inc;
            }
        }
        for (int i=1; i<length; i++){
            res[i] += res[i-1];
        }
        return res;
    }
};