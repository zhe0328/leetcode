class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_far = nums[0];
        int n = nums.size();
        for (int i=0;i<n;i++){
            if (i <= max_far) {
                max_far = max(max_far, i+nums[i]);
                if (max_far >= n - 1) {
                    return true;
                }
            }
        }
        return false;
    }
};