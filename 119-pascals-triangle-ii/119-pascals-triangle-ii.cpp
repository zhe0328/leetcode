class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> res(rowIndex+1, vector<int>());
        res[0].push_back(1);
        if (rowIndex == 0) return res[0];
        for (int i=1; i<rowIndex+1; i++){
            res[i].push_back(1);
            for (int j=1; j<i; j++){
                res[i].push_back(res[i-1][j-1] + res[i-1][j]);
            }
            res[i].push_back(1);
        }
        return res[rowIndex];
    }
};