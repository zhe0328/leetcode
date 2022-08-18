class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 1, cur = 1, cur_size = 1;
        while (cur < nums.size()){
            if (nums[cur] > nums[cur-1]){
                nums[k] = nums[cur];
                cur++;
                k++;
                cur_size = 1;
            }
            else if (cur_size < 2){
                nums[k] = nums[cur];
                cur++;
                k++;
                cur_size++;
            }
            else {
                cur++;
            }
        }
        return k;
    }
};