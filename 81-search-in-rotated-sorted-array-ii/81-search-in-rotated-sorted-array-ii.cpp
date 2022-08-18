class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) {
            return false;
        }
        if (n == 1) {
            return nums[0] == target;
        }
        int left = 0, right = n-1;
        while (left<=right){
            int mid = (right-left)/2+left;
            if (nums[mid] == target){
                return true;
            }
            if (nums[left] == nums[mid] && nums[mid] == nums[right]){
                left++;
                right--;
            }
            else if (nums[left] <= nums[mid]){
                if (nums[left] <= target && target <= nums[mid]){
                    right = mid-1;
                }
                else {
                    left = mid+1;
                }
            }
            else {
                if (nums[mid] <= target && target <= nums[right]){
                    left = mid+1;
                }
                else {
                    right = mid-1;
                }
            }
        }
        return false;
    }
};