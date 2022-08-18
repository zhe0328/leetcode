class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int pre = 0, max_res = nums[0];
        for (auto num : nums){
            pre = max(pre+num, num);
            max_res = max(max_res, pre);
        }
        return max_res;
        
    }
};