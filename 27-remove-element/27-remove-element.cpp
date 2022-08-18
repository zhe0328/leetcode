class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int cur = 0;
        for (auto num : nums){
            if (num != val){
                nums[cur] = num;
                cur++;
            }
        }
        return cur;
    }
};