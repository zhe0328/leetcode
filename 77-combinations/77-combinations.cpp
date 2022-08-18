class Solution {
public:
    // backtrack
    void dfs(int cur, int k, int n, vector<vector<int>> & res, vector<int> temp){
        if (temp.size() + (n - cur + 1) < k) return;
        if (temp.size() == k) {
            res.push_back(temp);
            return;
        }
        if (cur == n + 1) return;
        for (int i = cur;i<n+1;i++){
            temp.push_back(i);
            dfs(i+1, k, n, res, temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> temp;
        dfs(1, k, n, res, temp);
        return res;
    }
};