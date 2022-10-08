class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hashMap;
        vector<int> res;
        for (int i=0;i<nums.size();i++){
            if (hashMap.find(target-nums[i]) != hashMap.end()){
                auto idx = hashMap[target-nums[i]];
                res.push_back(i);
                res.push_back(idx);
                return res;
            }
            hashMap[nums[i]] = i;
        }
        return res;
    }
};