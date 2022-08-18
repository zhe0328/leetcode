class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        int n1 = num1.length()-1;
        int n2 = num2.length()-1;
        int mul[n1+n2+2];
        memset(mul, 0, sizeof(mul));
        
        for(int i = n1; i >= 0; --i) {
            for(int j = n2; j >= 0; --j) {
                int bitmul = (num1[i]-'0') * (num2[j]-'0');      
                bitmul += mul[i+j+1]; // 先加低位判断是否有新的进位
                
                mul[i+j] += bitmul / 10;
                mul[i+j+1] = bitmul % 10;
            }
        }
        int i = 0;
        // 去掉前导0
        string res;
        while(i < n1+n2+2 && mul[i] == 0){
            i++;
        }
        while(i < n1+n2+2){
            res+=to_string(mul[i]);
            i++;
        }
        return res;
    }
};