class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) return false;
        int temp = 0;
        int res = 0;
        int before = x;
        while (x > res){
            temp = x % 10;
            x /= 10;
            res = res * 10 + temp;
        }
        return x == res || x == res / 10;
    }
};