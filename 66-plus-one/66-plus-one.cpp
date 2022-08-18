class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int size = digits.size();
        for (int i=size-1; i>=0; i--){
            digits[i] = (digits[i] + 1) % 10;
            if (digits[i] != 0) {
                return digits;
            }
        }
        vector<int> ans(size + 1);
        ans[0] = 1;
        return ans;
    }
};