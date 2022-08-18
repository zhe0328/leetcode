class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        int res = exp(0.5*log(x));
        return ((long long) (res+1)*(res+1) <= x ? res+1: res);
    }
};