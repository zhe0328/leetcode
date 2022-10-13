class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int size = nums.size();
        vector<int> dp(size);
        dp[0] = nums[0];
        priority_queue<pair<int,int>> maxHeap;
        maxHeap.push({dp[0], 0});
        for (int i=1; i<size; i++){
            while (i-maxHeap.top().second > k){
                maxHeap.pop();
            }
            dp[i] = maxHeap.top().first + nums[i];
            maxHeap.push({dp[i], i});
        }
        return dp[size-1];
    }
};