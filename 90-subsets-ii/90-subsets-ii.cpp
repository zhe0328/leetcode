class Solution {
public:
    void dfs(bool choosePre, int cur, vector<int> &nums, vector<int> & s, vector<vector<int>> & res) {
        if (cur == nums.size()){
            res.push_back(s);
            return;
        }
        dfs(false, cur+1, nums, s, res);
        if (!choosePre && cur > 0 && nums[cur-1] == nums[cur]) {
            return;
        }
        s.push_back(nums[cur]);
        dfs(true, cur+1, nums, s, res);
        s.pop_back();
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> s;
        vector<vector<int>> res;
        dfs(false, 0, nums, s, res);
        return res;
    }
};