class Solution {
public:
    int minMoves(vector<int>& nums) {
        int minValue = *min_element(nums.begin(), nums.end());
        int res = 0;
        for (auto num:nums){
            res += num-minValue;
        }
        return res;
    }
};