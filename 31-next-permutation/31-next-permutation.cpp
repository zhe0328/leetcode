class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size()-2, j = nums.size()-1, k = nums.size()-1;
        while (i >= 0) {
            if (nums[i]<nums[j]){
                break;
            }
            else {
                i--;
                j--;
            }
        }
        if (i>=0){
            while (nums[i] >= nums[k]){
                k--;
            }
            swap(nums[i], nums[k]);
            sort(nums.begin()+j, nums.end());
        }
        else {
            sort(nums.begin(), nums.end());
        }
    }
};