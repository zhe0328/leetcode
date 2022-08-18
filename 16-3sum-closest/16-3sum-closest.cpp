class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int res = nums[0]+nums[1]+nums[2];
        for (int i=0;i<nums.size();i++){
            if(i>0 and nums[i]==nums[i-1]){
                continue;
            }
            int left = i+1, right = nums.size()-1;
            while (left < right){
                int temp = nums[i] + nums[left] + nums[right];
                if (temp == target) {
                    return target;
                }
                else if (temp > target){
                    right--;
                }
                else {
                    left++;
                }
                res = abs(target-res) < abs(target-temp) ? res : temp;
            }
        }
        return res;
    }
};