class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> record = {{0, 1}};
        int sum = 0, ans = 0;
        for (auto num:nums){
            sum+=num;
            int modulus = (sum % k + k) % k;
            if (record.find(modulus) != record.end()){
                ans+=record[modulus];
            }
            record[modulus]++;
        }
        return ans;
    }
};