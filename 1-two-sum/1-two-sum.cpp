class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hash_map;
        vector<int> solution;
        for (int i=0;i<nums.size();i++){
            auto it = hash_map.find(target - nums[i]);
            if (it != hash_map.end()){ // find 
                solution.push_back(i);
                solution.push_back(it->second);
                return solution;
            }
            hash_map[nums[i]] = i;
        }
        return solution;
    }
};