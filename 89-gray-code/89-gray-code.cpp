class Solution {
public:
    vector<int> grayCode(int n) {
        int total = pow(2,n);
        vector<int> res(total);
        for (int i = 0; i<total; i++){
            res[i] = i ^ (i>>1);
        }
        return res;
    }
};