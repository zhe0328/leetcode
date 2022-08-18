class Solution {
public:
    void dfs(vector<int>& candidates, int target, vector<vector<int>>& res, vector<int>& combine, int start){
        if (target == 0) {
            res.push_back(combine);
            return;
        }

        for (int i = start; i < candidates.size() && target - candidates[i] >= 0; i++) {
            if (i > start && candidates[i] == candidates[i-1])
                continue;
            combine.push_back(candidates[i]);
            // 元素不可重复利用，使用下一个即i+1
            dfs(candidates, target - candidates[i], res, combine, i+1);
            combine.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> combine;
        dfs(candidates, target, res, combine, 0);
        return res;
    }
};
