class Solution {
public:
    int divide(int dividend, int divisor) {
        int quotient = 0;
        int flag = ((dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0)) ? 1 : -1;
        if (dividend == INT_MIN && divisor == 1) return INT_MIN;
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        if (divisor == 1) return dividend;
        if (dividend == INT_MIN && divisor == INT_MIN) return 1;
        if (divisor == INT_MIN) return 0;
        if (dividend == INT_MIN){
            if (divisor < 0){
                dividend -= divisor;
            }
            else {
                dividend += divisor;
            }
            quotient++;
        }
        dividend = abs(dividend);
        divisor = abs(divisor);
        while (abs(dividend) >= abs(divisor)){
            for (int i = 31; i >= 0; i--) {
                if (dividend >> i >= divisor) {
                    quotient += 1 << i;
                    dividend -= divisor << i;
                }
            }
        }
        return flag * quotient;
    }
};    