class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int,int> hash_map;
        int cur = 0;
        for (auto num : nums){
            if (hash_map.find(num) == hash_map.end()){
                hash_map[num] = 1;
                nums[cur] = num;
                cur++;
            }
        }
        return cur; 
    }
};