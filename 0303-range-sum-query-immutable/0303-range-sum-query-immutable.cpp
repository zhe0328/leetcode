class NumArray {
private:
    vector<int> preSum;
public:
    NumArray(vector<int>& nums) {
        int size = nums.size();
        preSum.resize(size);
        for (int i=0; i<size; i++){
            preSum[i] = nums[i];
        }
        for (int i=1; i<nums.size(); i++){
            preSum[i] += preSum[i-1];
        }
    }
    
    int sumRange(int left, int right) {
        if (left == 0){
            return preSum[right];
        }
        return preSum[right]-preSum[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */