class Solution {
public:
    void backtrack(vector<int> & nums, vector<int> & cur, vector<vector<int>> & res, int * visited){
        if (cur.size() == nums.size()){
            res.push_back(cur);
            return;
        }
        for (int i=0; i<nums.size(); i++){
            if (visited[i] == 1) continue;
            if (i>0 && nums[i]==nums[i-1] && visited[i-1] == 1) continue;
            visited[i] = 1;
            cur.push_back(nums[i]);
            backtrack(nums, cur, res, visited);
            visited[i] = 0;
            cur.pop_back();
        }   
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> cur;
        int visited[nums.size()];
        backtrack(nums, cur, res, visited);
        return res;
    }
};