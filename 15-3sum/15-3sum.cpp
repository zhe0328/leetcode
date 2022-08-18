class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // sort(nums.begin(), nums.end());
        // cout<<nums[0]<<endl;
        // unordered_map<int, vector<int>> hash_map;
        // vector<vector<int>> ans;
        // for (int i=0; i <nums.size(); i++){
        //     if (hash_map.find(-nums[i]) == hash_map.end()){
        //         vector<int> res;
        //         res.push_back(i);
        //         hash_map[-nums[i]] = res;
        //     }
        //     else {
        //         vector<int> res = hash_map[-nums[i]];
        //         res.push_back(i);
        //         hash_map[-nums[i]] = res;
        //     }
        // }
        // for (int i=0; i<nums.size(); i++){
        //     for (int j=i+1; j<nums.size(); j++){
        //         int temp = nums[i] + nums[j];
        //         if (hash_map.find(temp) != hash_map.end()) {
        //             vector<int> res = hash_map[temp];
        //             for (int k = 0; k<res.size();k++){
        //                 if (res[k] > i && res[k] > j) {
        //                     vector<int> this_ans;
        //                     this_ans.push_back(nums[i]);
        //                     this_ans.push_back(nums[j]);
        //                     this_ans.push_back(nums[res[k]]);
        //                     ans.push_back(this_ans);
        //                 }
        //             }
        //         }
        //     }
        // }
        // return ans;
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        if (nums.size() < 3) return res;
        for (int i=0;i<nums.size();i++){
            if (nums[i] > 0) return res;
            if(i>0 and nums[i]==nums[i-1]){
                continue;
            }
            int left = i+1, right = nums.size()-1;
            while (left < right){
                if (nums[i] + nums[left] + nums[right] == 0) {
                    vector<int> ans;
                    ans.push_back(nums[i]);
                    ans.push_back(nums[left]);
                    ans.push_back(nums[right]);
                    res.push_back(ans);
                    while (left<right && nums[left] == nums[left+1]){
                        left++;
                    }
                    while (left<right && nums[right] == nums[right-1]){
                        right--;
                    }
                    left++;
                    right--;
                }
                else if (nums[i] + nums[left] + nums[right] > 0){
                    right--;
                }
                else {
                    left++;
                }
            }
        }
        return res;
    }
};