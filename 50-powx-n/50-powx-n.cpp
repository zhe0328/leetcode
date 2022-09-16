class Solution {
public:
    double compute(double x, long long n){
        double ans = 1.0;
        double x_cur = x;
        while (n > 0){
            if (n % 2 == 1){
                ans *= x_cur;
            }
            x_cur *= x_cur;
            n /= 2;
        }
        return ans;
    }
    double myPow(double x, int n) {
        long long N = n;
        return n >= 0 ? compute(x, N) : 1/compute(x, -N);
    }
};