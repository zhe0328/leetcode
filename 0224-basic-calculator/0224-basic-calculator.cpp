class Solution {
public:
    int strToInt(string s) {
        int sum = 0;
        for (int i=0; i<s.size(); i++){
            sum = sum * 10 + (s[i]-'0');
        }
        return sum;
    }
    int calculate(string s) {
        stack<int> stk;
        int i=0;
        int num = 0, ans = 0;
        int sign = 1;
        while (i<s.size()){
            if (isdigit(s[i])){
                string number;
                while (isdigit(s[i])){
                    number += s[i];
                    ++i;
                }
                --i;
                num = strToInt(number);
                num *= sign;
                ans += num;
            }
            else if (s[i] == '+'){
                sign = 1;
            }
            else if (s[i] == '-'){
                sign = -1;
            }
            else if (s[i] == '('){
                stk.push(ans);
                stk.push(sign);
                ans = 0;
                sign = 1;
            }
            else if (s[i] == ')'){
                ans *= stk.top();
                stk.pop();
                ans += stk.top();
                stk.pop();
            }
            ++i;
        }
        return ans;
    }
};