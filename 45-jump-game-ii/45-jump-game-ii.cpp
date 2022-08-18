class Solution {
public:
    int jump(vector<int>& nums) {
        int max_far=0, step=0, end=0; // max_far: 目前能跳到的最远位置 end:上次跳跃可达最远位置
        for (int i=0;i<nums.size()-1;i++){
            max_far = max(max_far, i+nums[i]);
            if (i == end){
                end = max_far;
                step++;
            }
        }
        return step;
    }
};
