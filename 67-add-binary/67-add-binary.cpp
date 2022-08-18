class Solution {
public:
    string addBinary(string a, string b) {
        int size1 = a.size();
        int size2 = b.size();
        while (size1 < size2) {
            a = '0' + a;
            size1++;
        }
        while (size2 < size1) {
            b = '0' + b;
            size2++;
        }
        string res;
        int carry = 0;
        for (int i=size1-1; i>=0; i--){
            int temp = (a[i]-'0' + b[i]-'0' + carry) % 2;
            carry = (a[i]-'0' + b[i]-'0' + carry) / 2;
            char temp_char = temp + '0';
            res = temp_char + res;
        }
        if (carry != 0){
            char carry_char = carry + '0';
            res = carry_char + res;
        }
        return res;
    }
};